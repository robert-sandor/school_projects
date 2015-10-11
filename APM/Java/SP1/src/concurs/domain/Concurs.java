package concurs.domain;

import concurs.repository.*;

public class Concurs {
private ParticipantRepository tabel;

public Concurs(ParticipantRepository tabel){
	this.setTabel(tabel);
}

public ParticipantRepository getTabel() {
	return tabel;
}

public void setTabel(ParticipantRepository tabel) {
	this.tabel = tabel;
}

public String toString(){
	String r = " ";
	Participant[] arr= tabel.getParticipants();
	if (arr==null)
		return "";
	for(int i=0;i<arr.length;i++)
		r=r+arr[i].toString()+" ";
	return r;
}
}
