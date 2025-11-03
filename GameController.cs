using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections.Generic;
using System.IO; 
using System.Linq;
using UnityEngine.SceneManagement; 
using System.Collections;

public class GameManager : MonoBehaviour
{
  
    [Header("Painéis da UI")]
    public GameObject painelInicialPreto;
    public GameObject grupoDialogo;
    public GameObject grupoDificuldade;
    public GameObject painelJogo;
    public GameObject painelFimDeJogoVitoria;
    public GameObject painelFimDeJogoDerrota;
    public GameObject botaoDialogo;
    public GameObject Perguntas_Respostas;
    public GameObject painelFeedback;
    public GameObject painelPause; 
    public GameObject painelAjuda; 

    [Header("Componentes do Diálogo")]
    public List<GameObject> caixasDeDialogo;
    [Header("Configurações de Digitação")]
    public float velocidadeDeDigitacao = 0.04f;
    private List<string> textosCompletos = new List<string>();
    private int indiceDialogoAtual = 0;
    private bool estaDigitando = false;
    private Coroutine rotinaDeDigitacaoAtual;

    [Header("Componentes do Jogo / HUD")]
    public TextMeshProUGUI textoPergunta;
    public TMP_InputField campoResposta;
    public Button botaoEnviar;
    public TextMeshProUGUI textoVidas;
    public Button botaoReiniciar; 
    [Header("Referências do Jogo")]
    public Cego cego;
    public GameObject objetoPaiDasPlataformas;
    public TextMeshProUGUI textoFeedback;
    [Header("Componentes da Ajuda")]
    public GameObject conteudoAjudaFacil;  
    public GameObject conteudoAjudaMedio;  
    public GameObject conteudoAjudaDificil;

   
    private List<List<Questao>> todosOsNiveisDePerguntas;
    public int nivelPerguntaAtual = 0;
    private Questao questaoAtual;
    private int vidas = 3;
   private int dificuldadeSelecionada;

    void Start()
    {
       
        painelInicialPreto.SetActive(true);
        grupoDialogo.SetActive(true);
        grupoDificuldade.SetActive(false);
        painelJogo.SetActive(false);
        campoResposta.onSubmit.AddListener(OnSubmitResposta);
       

        
        botaoEnviar.onClick.AddListener(VerificarResposta);
        botaoReiniciar.onClick.AddListener(ReiniciarPartida);
        PrepararDialogos();
    }

   void Update()
{
    
    

        {
        if (Input.GetKeyDown(KeyCode.Return))
        {
            if (!grupoDialogo.activeSelf) return;
            if (estaDigitando)
            {
                
                CompletarTexto();
            }
            else
            {
               
                AvancarDialogo();
            }
            
        }
        }
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if (painelAjuda.activeSelf)
            {
                FecharPainelAjuda(); 
            }
            else if (painelPause.activeSelf)
            {
                RetomarJogo();
            }

            else if (painelJogo.activeSelf)
            {
                PausarJogo();
            }
        }
}

    void PrepararDialogos()
    {
        if (caixasDeDialogo == null || caixasDeDialogo.Count == 0)
        {
            grupoDialogo.SetActive(false);
            return;
        }

        textosCompletos.Clear();
        for (int i = 0; i < caixasDeDialogo.Count; i++)
        {
            
            textosCompletos.Add(caixasDeDialogo[i].GetComponentInChildren<TextMeshProUGUI>().text);
           
            caixasDeDialogo[i].SetActive(false);
        }

        indiceDialogoAtual = 0;
        IniciarDigitacao(indiceDialogoAtual);
    }

    void IniciarDigitacao(int indice)
    {
        caixasDeDialogo[indice].SetActive(true);
        TextMeshProUGUI textoUI = caixasDeDialogo[indice].GetComponentInChildren<TextMeshProUGUI>();
        rotinaDeDigitacaoAtual = StartCoroutine(DigitarTexto(textoUI, textosCompletos[indice]));
    }

    public void CompletarTexto()
    {
        if (rotinaDeDigitacaoAtual != null)
        {
            StopCoroutine(rotinaDeDigitacaoAtual);
        }
        caixasDeDialogo[indiceDialogoAtual].GetComponentInChildren<TextMeshProUGUI>().text = textosCompletos[indiceDialogoAtual];
        estaDigitando = false;
    }
    public void TentarAvancarDialogo()
{
    
    if (!grupoDialogo.activeSelf) return;

    if (estaDigitando)
    {
        
        CompletarTexto();
    }
    else
    {
        
        AvancarDialogo();
    }
}

    public void AvancarDialogo()
    {
        caixasDeDialogo[indiceDialogoAtual].SetActive(false);
        
        indiceDialogoAtual++;

        
        if (indiceDialogoAtual < caixasDeDialogo.Count)
        {
            IniciarDigitacao(indiceDialogoAtual);
        }
        else
        {
            botaoDialogo.SetActive(false);
            grupoDialogo.SetActive(false);
            grupoDificuldade.SetActive(true);
        }
    }

    IEnumerator DigitarTexto(TextMeshProUGUI textoUI, string textoCompleto)
    {
        estaDigitando = true;
        textoUI.text = "";
        foreach (char letra in textoCompleto.ToCharArray())
        {
            textoUI.text += letra;
            yield return new WaitForSeconds(velocidadeDeDigitacao);
        }
        estaDigitando = false;
    }

    public void SelecionarDificuldade(int nivel)
    {
        dificuldadeSelecionada = nivel;
        string nomeArquivo = "";
        switch (nivel)
        {
            case 1: nomeArquivo = "QuizFacil"; break;
            case 2: nomeArquivo = "QuizMedio"; break;
            case 3: nomeArquivo = "QuizDificil"; break;
        }

        CarregarPerguntasDoArquivo(nomeArquivo);
        
        painelInicialPreto.SetActive(false);
        grupoDificuldade.SetActive(false);
        painelJogo.SetActive(true);
        ConfigurarJogo();
    }

    void CarregarPerguntasDoArquivo(string nomeArquivo)
    {
        todosOsNiveisDePerguntas = new List<List<Questao>>();
        TextAsset arquivoCsv = Resources.Load<TextAsset>(nomeArquivo);
        
        string[] linhas = arquivoCsv.text.Split('\n');

        for (int i = 0; i < 7; i++)
        {
            var nivelAtual = new List<Questao>();
            var perguntasDoNivel = linhas.Skip(i * 10).Take(10);

            foreach (var linha in perguntasDoNivel)
            {
                if (string.IsNullOrWhiteSpace(linha)) continue;
                string[] campos = linha.Trim().Split(';');
                Questao q = new Questao { pergunta = campos[0], resposta = int.Parse(campos[1]) };
                nivelAtual.Add(q);
            }
            todosOsNiveisDePerguntas.Add(nivelAtual);
        }
    }

    void ConfigurarJogo()
    {
        nivelPerguntaAtual = 0;
        vidas = 3;
        AtualizarUI();
        ProximaPergunta();
    }

    void ProximaPergunta()
    {
        if (nivelPerguntaAtual >= todosOsNiveisDePerguntas.Count)
        {
            painelJogo.SetActive(false);
            return;
        }
        
        List<Questao> poolDePerguntas = todosOsNiveisDePerguntas[nivelPerguntaAtual];
        int indiceAleatorio = Random.Range(0, poolDePerguntas.Count);
        questaoAtual = poolDePerguntas[indiceAleatorio];

        textoPergunta.text = questaoAtual.pergunta;
        campoResposta.text = "";
        campoResposta.DeactivateInputField();
        campoResposta.ActivateInputField(); 
    }
    public void OnSubmitResposta(string texto)
    {
        if (painelJogo.activeSelf && campoResposta.interactable)
        {
            VerificarResposta();
        }
    }

    public void VerificarResposta()
    {
        int respostaDoUsuario;
    if (int.TryParse(campoResposta.text, out respostaDoUsuario))
    {
        bool acertou = (respostaDoUsuario == questaoAtual.resposta);
        
        objetoPaiDasPlataformas.SetActive(acertou);
        
        cego.IniciarMovimento();

        campoResposta.interactable = false;
        botaoEnviar.interactable = false;
        Perguntas_Respostas.SetActive(false);
            if (acertou)
            {
                textoFeedback.text = $"<color=green>Acertou!</color>\nA resposta era {questaoAtual.resposta}.";
            }
            else
            {
                textoFeedback.text = $"<color=red>Errou!</color>\nA resposta era {questaoAtual.resposta}.";
            }
            painelFeedback.SetActive(true);
    }
    }
    public void JogadorCaiuNosEspinhos()
{
    vidas--; 
    AtualizarUI();

    if (vidas > 0)
    {
        
        cego.Respawn();
    }
    else
    {
       painelFeedback.SetActive(false);
        Derrota();
    }
}
public void PrepararNovaPergunta(bool foiAcerto)
{
    painelFeedback.SetActive(false);
    Perguntas_Respostas.SetActive(true);
    if (foiAcerto)
    {
        nivelPerguntaAtual++; 
    }
  
    ProximaPergunta();
    
    
    campoResposta.interactable = true;
    botaoEnviar.interactable = true;
    campoResposta.ActivateInputField();
}

    void AtualizarUI()
    {
       textoVidas.text = vidas.ToString();
    }

   public void Vitoria()
    {
        painelJogo.SetActive(false);
        painelFimDeJogoVitoria.SetActive(true);
    }

    void Derrota()
    {
        painelJogo.SetActive(false);
        painelFimDeJogoDerrota.SetActive(true);
    }

   public void ReiniciarPartida()
{
    painelFimDeJogoVitoria.SetActive(false);
    painelFimDeJogoDerrota.SetActive(false);

    painelJogo.SetActive(true);
    painelFeedback.SetActive(false);
    Perguntas_Respostas.SetActive(true);

    cego.ResetPosicao();
     campoResposta.interactable = true;
     botaoEnviar.interactable = true;
    ConfigurarJogo();
}
public void VoltarParaMenu()
{
    Time.timeScale = 1f;
    SceneManager.LoadScene("Menu"); 
}
public void PausarJogo()
    {
        
        
       Time.timeScale = 0f; //pausar as animaçôes
        painelPause.SetActive(true);
        painelJogo.SetActive(false);
    }
    public void RetomarJogo()
    {
       
        painelPause.SetActive(false);
        painelAjuda.SetActive(false); 
        painelJogo.SetActive(true);
        
        
        Time.timeScale = 1f; 
    }
    public void AbrirPainelAjuda()
    {
        painelPause.SetActive(false);
        painelAjuda.SetActive(true);
        conteudoAjudaFacil.SetActive(false);
        conteudoAjudaMedio.SetActive(false);
        conteudoAjudaDificil.SetActive(false);

        switch (dificuldadeSelecionada)
        {
            case 1: // Fácil
                conteudoAjudaFacil.SetActive(true);
                break;
            case 2: // Médio
                conteudoAjudaMedio.SetActive(true);
                break;
            case 3: // Difícil
                conteudoAjudaDificil.SetActive(true);
                break;
        }
    }

    public void FecharPainelAjuda()
    {
        painelAjuda.SetActive(false);
        painelPause.SetActive(true);
    }
}