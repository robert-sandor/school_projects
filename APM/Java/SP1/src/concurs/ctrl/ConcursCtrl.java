package concurs.ctrl;

import concurs.domain.*;

public class ConcursCtrl {
	private Concurs concurs;
	
	public ConcursCtrl(Concurs concurs){
		this.concurs=concurs;
	}

	public Concurs getConcurs() {
		return concurs;
	}

	public void setConcurs(Concurs concurs) {
		this.concurs = concurs;
	}
	
    public void addNewParticipant(Participant p){
	if(concurs.getTabel().addNewParticipant(p)==false)
		System.out.printf("Participant " +p.toString()+ "cannot be added\n.");
	else
		System.out.printf("Participant " +p.toString()+ "has been added\n.");
	}
    
	public void setNota(int n, int id){
		if(concurs.getTabel().setNota(n,id)==false)
			System.out.printf("The grade cannot be set to Participant " +id+ "\n.");
		else
			System.out.printf("The grade has been set to Participant " +id+ "\n.");
		}
	

	public void delParticipant(int id){
		if(concurs.getTabel().delParticipant(id)==false)
			System.out.printf("The Participant " +id+ "cannot be deleted\n.");
		else
			System.out.printf("The Participant " +id+ "has been deleted\n.");
		}
	
	
	public Participant[] getParticipants(){
		return concurs.getTabel().getParticipants();
	}
	
}
