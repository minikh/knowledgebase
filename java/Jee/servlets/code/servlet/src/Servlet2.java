import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by minik_000 on 02.04.2014.
 */
@WebServlet(urlPatterns = "/metod1", name = "s2")
public class Servlet2 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            response.setContentType("text/html");
            response.setCharacterEncoding("utf-8");
            PrintWriter printWriter = response.getWriter();
            printWriter.println("<form method=\"post\" action = \"simpleservlet\">");
            printWriter.println("<h2>");
            printWriter.println("Сервлет 2 работает. doPost");
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
            printWriter.println("<form method=\"get\" action = \"simpleservlet\">");
            printWriter.println("<h2>");
            printWriter.println("Сервлет 2 работает. doGet");
            printWriter.println("<h2>");
            printWriter.println("<input type=\"submit\" value = \"отправить\">");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
