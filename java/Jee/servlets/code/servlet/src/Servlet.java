import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.xml.ws.Endpoint;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by minik_000 on 02.04.2014.
 */
//@WebServlet(urlPatterns = {"/simpleservlet","*.w"})
@WebServlet(urlPatterns = "/simpleservlet", name = "s1")
public class Servlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            startServices();
            response.setContentType("text/html");
            response.setCharacterEncoding("utf-8");
            PrintWriter printWriter = response.getWriter();
            printWriter.println("<form method=\"get\" action = \"metod1\">");
            printWriter.println("<h2>");
            printWriter.println("Сервлет 1 работает. doPost");
            printWriter.println("<h2>");
            printWriter.println("<input type=\"submit\" value = \"отправить\">");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {

            response.setContentType("text/html");
            response.setCharacterEncoding("utf-8");
            PrintWriter printWriter = response.getWriter();
            printWriter.println("<form method=\"post\" action = \"metod1\">");
            printWriter.println("<h2>");
            printWriter.println("Сервлет 1 работает. doGet");
            printWriter.println("<input type=\"submit\" value = \"отправить\">");
        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    public void startServices(){
        System.out.println("start service");
        Object implementor = null;
        if (implementor == null) {
            implementor= new HelloWorld ();
            String address = "http://localhost:9000/HelloWorld";
            Endpoint.publish(address, implementor);
        }
    }
}
