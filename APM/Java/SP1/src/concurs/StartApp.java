package concurs;

import concurs.ctrl.*;
import concurs.domain.*;
import concurs.repository.array.*;

public class StartApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ParticipantRepositoryArray pRepA = new ParticipantRepositoryArray(20);
		Concurs concurs = new Concurs(pRepA);
		ConcursCtrl concursCtrl = new ConcursCtrl(concurs);
		
		concursCtrl.addNewParticipant(new Participant(1,"A",10));
		System.out.println("Concurs:\n" + concursCtrl.getConcurs().toString());
		
	}
}