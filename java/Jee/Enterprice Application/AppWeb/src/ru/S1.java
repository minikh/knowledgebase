package ru;

import javax.ejb.EJB;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingEnumeration;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by minik_000 on 01.05.2014.
 */
@WebServlet(urlPatterns = "/s1", loadOnStartup = 10)
public class S1 extends javax.servlet.http.HttpServlet {

    private long id;
    @EJB (beanName = "F1")
    private FacadeBeanRemote f;

    @Override
    public void destroy() {
        System.out.println("------ Servlet id = " + id + " удален");
        super.destroy();
    }

    @Override
    public void init() throws ServletException {
        super.init();
        id = System.currentTimeMillis();
        System.out.println("------ Servlet id = " + id + " создан");
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();

        System.out.println("doGet");

        out.print("<html>");
        out.print("<hr/>Мой непервый сервлет. doGet");
        Context ctx = null;
        try {
            ctx = new InitialContext();
            FacadeBeanRemote o = (FacadeBeanRemote) ctx.lookup("java:global/App1/Model/F1!ru.FacadeBeanRemote");
            out.print("<hr/> 1. " + o.info());
            out.print("<hr/> 1. " + f.info());
//            out.print("<hr/> 1. " + o.info());

        } catch (NamingException e) {
//            out.print("<hr/>Ошибка " + e);
            System.out.println(e.getMessage());
        } finally {
            try {
                ctx.close();
            } catch (NamingException e) {
                out.print("<hr/>Ошибка " + e);
            }
        }



        out.print("</html>");

        out.close();
    }

//    @Override
//    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
//        resp.setContentType("text/html; charset=UTF-8");
//        PrintWriter out = resp.getWriter();
//        out.print("<html>");
//        out.print("<hr/>Мой непервый сервлет. Service");
//        Thread thread = Thread.currentThread();
//        out.print("<hr/>" + thread);
////        try {
////            Thread.sleep(3000);
////        } catch (InterruptedException e) {
////            e.printStackTrace();
////        }
//
//        //доступ к  JNDI
//        Context context = null;
//        Long c = 0L;
//        try {
//            context = new InitialContext();
//            try {
//                context.bind("myName", c);
//            } catch (NamingException e) {}
//            c = (Long) context.lookup("myName");
//            c++;
//            out.print("<hr/>" + c);
//            context.rebind("myName", c);
//            NamingEnumeration ne = context.list("");
//            while (ne.hasMoreElements()){
//                Object o = ne.nextElement();
//                out.print("<hr/>" + o);
//            }
//        } catch (Exception e){
//            out.print("<hr/>Ошибка " + e);
//        } finally {
//            try {
//                context.close();
//            } catch (NamingException e) {
//                out.print("<hr/>Ошибка " + e);
//            }
//        }
//
//        out.print("</html>");
//        out.close();
//    }
}
