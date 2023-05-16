// PagmoExample_Cmake.cpp : Defines the entry point for the application.
//

#include "PagmoExample_Cmake.h"

using namespace pagmo;

// Our simple example problem, version 0.
struct problem_v1 {
    // Number of equality constraint 
    vector_double::size_type get_nec() const {
        return  1;
    }
    // number of inequality constraint
    vector_double::size_type get_nic() const {
        return 1;
    }


    // Implementation of the objective function.
    vector_double fitness(const vector_double& dv) const
    {
        return {
            dv[0] * dv[3] * (dv[0] + dv[1] + dv[2]) + dv[2], //obj fun 
            dv[0] * dv[0] + dv[1] * dv[1] + dv[2] * dv[2] + dv[3] * dv[3] - 40., // equality con.
            25. - dv[0] * dv[1] * dv[2] * dv[3]                                  // inequality con.
        };
    }
    // Implementation of the box bounds.
    std::pair<vector_double, vector_double> get_bounds() const
    {
        return { {1., 1., 1., 1.}, {5., 5., 5., 5.} };
    }
};

int main()
{
    // Construct a pagmo::problem from our example problem.
    problem p{ dtlz(1, 10, 2) };

    // Compute the value of the objective function
    // in the point (1, 2, 3, 4).
   // std::cout << "Value of the objfun in (1, 2, 3, 4): " << p.fitness({ 1, 2, 3, 4 })[0] << '\n';

    //compute fitness: obj func + eq + ineq 


    //p.set_seed(3);
    // 2 - Instantiate a pagmo algorithm
    algorithm algo{ nsga2(100) };
    algo.set_seed(3);

    population pop{ p, 24, 3 };

    pop = algo.evolve(pop);

    // Print p to screen.
    std::cout << pop << '\n';
}