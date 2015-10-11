package concurs.repository;

import concurs.domain.*;

public interface ParticipantRepository {

	Boolean addNewParticipant(Participant p);
	Boolean setNota(int n, int id);
	Boolean delParticipant(int id);
	Participant[] sortParticipants();
	Participant[] getParticipants();
	Boolean existParticipant(int id);
	Participant findParticipant(int id);
}
