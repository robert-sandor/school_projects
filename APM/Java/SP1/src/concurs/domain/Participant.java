package concurs.domain;

public class Participant {
	private int id;
	private String nume;
	private int nota;
	
	Participant(){
		id=0;
		nume=null;
		nota=0;
	}

	public Participant(int id, String nume, int nota){
		this.id=id;
		this.nume=nume;
		this.nota=nota;
	}

	public void setId(int id){
		this.id=id;
	}
	
	public int getId(){
		return id;
	}
	
	public void setNota(int nota){
		this.nota=nota;
	}
	
	public int getNota(){
		return nota;
	}
	
	public void setNume(String nume){
		this.nume=nume;
	}
	
	public String toString(){
        return id +" "+nume+ " " +nota;
    }
	
}
