using Interpreter.domain;

namespace Interpreter.repository
{
    public interface IRepository
    {
        void Add(ProgramState state);
        ProgramState GetCurentProgramState(int pos);
    }
}