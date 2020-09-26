import javax.mail.*;
import java.io.*;
import java.net.URL;
import java.util.Properties;
//import com.docraptor.*;
import java.net.*;
import com.openhtmltopdf.DOMBuilder;
import com.openhtmltopdf.pdfboxout.PdfRendererBuilder;
import com.openhtmltopdf.pdfboxout.PdfRendererBuilder.TextDirection;
import org.jsoup.Jsoup;

public class EmailService {

	private static boolean textIsHtml = false;

	public static void main(String[] args) {

		EmailService gmail = new EmailService();
		gmail.read();

	}


	public void read() {

		Properties props = new Properties();
		try {
			props.load(new FileInputStream(new File("A:\\smtp.properties")));
			Session session = Session.getDefaultInstance(props, null);

			Store store = session.getStore("imaps");
			store.connect("smtp.gmail.com", "aabc0041@gmail.com", "rfvtgbyhn");

			Folder inbox = store.getFolder("inbox");

			inbox.open(Folder.READ_ONLY);
			int messageCount = inbox.getMessageCount();

			System.out.println("Total Messages:- " + messageCount);

			Message[] messages = inbox.getMessages();
			System.out.println("------------------------------");

			for (int i = messageCount-1; i > messageCount -2; i--) {
				System.out.println("------------------------------");
				System.out.println("Mail Subject:- " + messages[i].getSubject());
				System.out.println("Mail Content:- " + EmailService.getText(messages[i]) );
				System.out.println("Mail sent date:- " + messages[i].getSentDate());
				System.out.println("Mail from:- " + messages[i].getFrom()[0]);

			}
			PrintWriter writer = new PrintWriter("mail.html", "UTF-8");
			writer.println("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"https://www.w3.org/TR/html4/strict.dtd\">");
			writer.println(EmailService.getText(messages[924]));
			writer.close();




			inbox.close(true);
			store.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}




	private static  String getText(Part p) throws
			MessagingException, IOException {
		if (p.isMimeType("text/*")) {
			String s = (String)p.getContent();
			EmailService.textIsHtml = p.isMimeType("text/html");
			return s;
		}

		if (p.isMimeType("multipart/alternative")) {
			// prefer html text over plain text
			Multipart mp = (Multipart)p.getContent();
			String text = null;
			for (int i = 0; i < mp.getCount(); i++) {
				Part bp = mp.getBodyPart(i);
				if (bp.isMimeType("text/plain")) {
					if (text == null)
						text = getText(bp);
					continue;
				} else if (bp.isMimeType("text/html")) {
					String s = getText(bp);
					if (s != null)
						return s;
				} else {
					return getText(bp);
				}
			}
			return text;
		} else if (p.isMimeType("multipart/*")) {
			Multipart mp = (Multipart)p.getContent();
			for (int i = 0; i < mp.getCount(); i++) {
				String s = getText(mp.getBodyPart(i));
				if (s != null)
					return s;
			}
		}

		return null;
	}

}
