using UnityEngine;
using UnityEngine.SceneManagement; 

public class MenuController : MonoBehaviour
{
    
    public void IniciarJogo()
    {
        
        SceneManager.LoadScene("Aventura"); 
    }

 
    public void SairDoJogo()
    {
        Debug.Log("Saindo do jogo...");
        Application.Quit();

        
        #if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
        #endif
    }
}