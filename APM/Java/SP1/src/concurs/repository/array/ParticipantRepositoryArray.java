package concurs.repository.array;

import concurs.domain.Participant;
import concurs.repository.*;

public class ParticipantRepositoryArray implements ParticipantRepository {

	private Participant[] tabel;
	private int size,capacity;
	
	public ParticipantRepositoryArray(int capacity){
		tabel = new Participant[capacity];
		setSize(-1);
		setCapacity(capacity);
	}
	
	
	
	@Override
	public Boolean addNewParticipant(Participant p) {
		if (existParticipant(p.getId())) 
			return false;
		size=size+1;
		if(size==capacity)
			return false;
		tabel[size]=p;
		return true;
	}

	@Override
	public Boolean setNota(int n, int id) {
		Participant p = findParticipant(id);
		if (p==null)
			return false;
		p.setNota(n);
		return true;
	}

	@Override
	public Boolean delParticipant(int id) {
		Boolean notFound=true;
		int i=0;
		while(notFound && (i<=size)){
			if(tabel[i].getId()==id)
				notFound=false;
				else
					i++;
					
		}
		if(notFound==false){
			if(i<size){
				for(int j=i;j<size;j++)
					tabel[j]=tabel[j+1];
			}
			size=size-1;
			return true;
		}else
			return false;
		}

	@Override
	public Participant[] sortParticipants() {
		// TODO Auto-generated method stub
		return tabel;
	}

	@Override
	public Participant[] getParticipants() {
		// TODO Auto-generated method stub
		if(size>=0){
			
			Participant[] rez= new Participant[size+1];
			for(int i=0;i<=size;i++)
				rez[i]=tabel[i];
			return rez;
		}
		else 
			return null;
	}



	public int getCapacity() {
		return capacity;
	}



	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}



	public int getSize() {
		return size;
	}



	public void setSize(int size) {
		this.size = size;
	}



	public Boolean existParticipant(int id) {
		for(int i=0;i<=size;i++){
			if(id ==tabel[i].getId())
				return true;
		}
		return false;
	}



	







	@Override
	public Participant findParticipant(int id) {
		for(int i=0;i<=size;i++){
			if(tabel[i].getId()==id)
				return tabel[i];
		}
		
		return null;
	}
	

}
