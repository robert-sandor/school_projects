package ro.sandorrobertk94.repository;

import ro.sandorrobertk94.domain.ProgramState;

/**
 * Created by robert on 10/25/15.
 */
public interface IRepository {
    ProgramState getCurrentProgram(int pos);
}
