using UnityEngine;
using System.Collections;

public class Blind : MonoBehaviour
{
    
   [Header("Configurações")]
    public float velocidadeDeMovimento = 3f;
    public GameController gameController;
    private Animator animator;
    private Rigidbody2D rb;
    private bool andando = false;
    private Vector3 ultimaPosicaoSegura;
    private Vector3 posicaoInicial;
    private bool podeInteragir = true;
    

    void Awake()
    {
        rb = GetComponent<Rigidbody2D>();
        ultimaPosicaoSegura = transform.position;
        posicaoInicial = transform.position;
        animator = GetComponent<Animator>();
    }
    void Update()
    {
        animator.SetBool("Andando", andando);
    }

    void FixedUpdate()
    {
        if (andando)
        {
  
            rb.linearVelocity = new Vector2(transform.right.x * velocidadeDeMovimento, rb.linearVelocity.y);
        }
    }

    
    public void IniciarMovimento()
    {
        ultimaPosicaoSegura = transform.position;
        andando = true;
        podeInteragir = true;
    }

    
    private void OnTriggerEnter2D(Collider2D other)
    {
        // Se encostou em um Ponto de Parada
        if (other.CompareTag("PontoDeParada") && podeInteragir)
        {
            andando = false;
            rb.linearVelocity = Vector3.zero; 
            gameController.PrepararNovaPergunta(true); 
            
        }

        if (other.CompareTag("Espinho"))
        {
            andando = false;
            rb.linearVelocity = Vector3.zero;
            podeInteragir = false;
            gameController.JogadorCaiuNosEspinhos(); 
            
        }
        if (other.CompareTag("Padaria"))
        {
            andando = false;
            rb.linearVelocity = Vector3.zero;
            gameController.Vitoria();
        }
    }

    public void Respawn()
    {
        transform.position = ultimaPosicaoSegura;
        gameController.PrepararNovaPergunta(false);
    }
    public void ResetPosicao()
    {
        
        andando = false;
        rb.linearVelocity = Vector2.zero;
        transform.position = posicaoInicial;
        podeInteragir = true;
    }

}
