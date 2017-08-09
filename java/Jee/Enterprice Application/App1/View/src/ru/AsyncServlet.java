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
 * Created by minik_000 on 04.05.2014.
 */
@WebServlet(urlPatterns = "/asyncservlet", loadOnStartup = 10, name = "AsyncServlet")
public class AsyncServlet extends HttpServlet {

    @EJB
    private FacadeBeanLocal f;

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();
        out.print("<html>");
        out.print("<hr/>AsyncServlet сервлет. Service");

        out.print("<hr/>" + f.testAsync());
//        out.print("<br> Метод test выполнен");

        out.print("</html>");
    }
}
