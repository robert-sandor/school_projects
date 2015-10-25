using Interpreter.domain;

namespace Interpreter.repository
{
    public class Repository : IRepository
    {
        private ProgramState[] programs;
        private int numberOfPrograms;

        public Repository()
        {
            programs = new ProgramState[10];
            numberOfPrograms = 0;
        }

        public void Add(ProgramState state)
        {
            programs[numberOfPrograms] = state;
            numberOfPrograms++;
        }


        public ProgramState GetCurentProgramState(int pos)
        {
            if (pos < numberOfPrograms)
            {
                return programs[pos];
            }
            return null;
        }
    }
}