import java.nio.file.Path;
import java.nio.file.Files;
import java.nio.file.FileSystems;
import java.io.IOException;

public class Readfifo {
    public static void main(String[] args) throws IOException {
        System.out.println("Hello from Java!");
        Path p = FileSystems.getDefault().getPath("fifo");
        Readfifo r = new Readfifo(p);
        r.run();
        System.out.println("Quittin!");
    }

    private boolean quit = false;
    private Path p;

    public Readfifo(Path p) {
        this.p = p;
    }

    public void run() throws IOException {
        while (!quit) {
            Files.lines(p).forEach((s) -> handle(s));
        }
    }

    private void handle(String s) {
        if (s.equals("quit")) {
            quit = true;
        }
        System.out.println("Java read on FIFO: " + s);
    }
}

