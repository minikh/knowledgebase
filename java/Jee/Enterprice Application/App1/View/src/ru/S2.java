package ru;

import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by minik_000 on 03.05.2014.
 */
@WebServlet(urlPatterns = "/s2", loadOnStartup = 10, name = "S2")
public class S2 extends HttpServlet {
    @EJB
    private FacadeBeanLocal f;

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();
        out.print("<html>");
        out.print("<hr/>S2 сервлет. Service");

        f.stopJob();
        out.print("<br>Задание остановлено");

        out.print("</html>");
    }
}
