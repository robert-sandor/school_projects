using Interpreter.domain;

namespace Interpreter.repository
{
    public interface IRepository
    {
        ProgramState GetCurentProgramState(int pos);
    }
}