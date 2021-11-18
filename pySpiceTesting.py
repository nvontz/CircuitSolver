import PySpice.Logging.Logging as Logging

logger = Logging.setup_logging()

from PySpice.Spice.Netlist import Circuit
from PySpice.Unit import *

netlist = open("netlists/netlist1/Netlist1.net", "r")

circuit = Circuit(netlist)

#circuit.V('input', 'a', circuit.gnd, 10@u_V)
#circuit.R(1, 'a', 'out', 10@u_kOhm)
#circuit.R(2, 'out', circuit.gnd, 1@u_kOhm)

simulator = circuit.simulator(temperature=25, nominal_temperature=25)

analysis = simulator.operating_point()
for node in (analysis['a'], analysis.out):
    print('Node {}: {} V'.format(str(node), float(node)))

