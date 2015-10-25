package ro.sandorrobertk94.repository;

import ro.sandorrobertk94.domain.ProgramState;

/**
 * Created by robert on 10/25/15.
 */
public class Repository implements IRepository {
    private ProgramState[] programs;
    private int numberOfPrograms;

    public Repository() {
        programs = new ProgramState[10];
        numberOfPrograms = 0;
    }

    public void add(ProgramState prgState) {
        programs[numberOfPrograms] = prgState;
        numberOfPrograms++;
    }

    @Override
    public ProgramState getProgState(int pos) {
        if (pos < numberOfPrograms) {
            return programs[pos];
        }
        return null;
    }
}
