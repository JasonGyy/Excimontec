// Copyright (c) 2017 Michael C. Heiber
// This source file is part of the Excimontec project, which is subject to the MIT License.
// For more information, see the LICENSE file that accompanies this software.
// The Excimontec project can be found on Github at https://github.com/MikeHeiber/Excimontec

#include "OSC_Sim.h"

using namespace std;
using namespace Utils;

OSC_Sim::OSC_Sim() {

}

OSC_Sim::~OSC_Sim() {

}

bool OSC_Sim::init(const Parameters_OPV& params,const int id){
	// Check parameters for errors
	if (!checkParameters(params)) {
		Error_found = true;
		return false;
	}
	bool success;
    // Set parameters of Simulation base class
    Simulation::init(params,id);
    // Set Additional General Parameters
    Bias = params.Bias;
    // Morphology Parameters
    Enable_neat = params.Enable_neat;
    Enable_bilayer = params.Enable_bilayer;
    Thickness_donor = params.Thickness_donor;
    Thickness_acceptor = params.Thickness_acceptor;
    Enable_random_blend = params.Enable_random_blend;
    Acceptor_conc = params.Acceptor_conc;
    Enable_import_morphology = params.Enable_import_morphology;
    Morphology_file = params.Morphology_file;
    // Test Parameters
    N_tests = params.N_tests;
    Enable_exciton_diffusion_test = params.Enable_exciton_diffusion_test;
    Enable_ToF_test = params.Enable_ToF_test;
    ToF_polaron_type = params.ToF_polaron_type;
    ToF_initial_polarons = params.ToF_initial_polarons;
    ToF_transient_start = params.ToF_transient_start;
    ToF_transient_end = params.ToF_transient_end;
    ToF_pnts_per_decade = params.ToF_pnts_per_decade;
    Enable_IQE_test = params.Enable_IQE_test;
    IQE_time_cutoff = params.IQE_time_cutoff;
    Enable_dynamics_test = params.Enable_dynamics_test;
    Enable_dynamics_extraction = params.Enable_dynamics_extraction;
    Dynamics_initial_exciton_conc = params.Dynamics_initial_exciton_conc;
    Dynamics_transient_start = params.Dynamics_transient_start;
    Dynamics_transient_end = params.Dynamics_transient_end;
    Dynamics_pnts_per_decade = params.Dynamics_pnts_per_decade;
    // Exciton Parameters
    Exciton_generation_rate_donor = params.Exciton_generation_rate_donor;
    Exciton_generation_rate_acceptor = params.Exciton_generation_rate_acceptor;
    Singlet_lifetime_donor = params.Singlet_lifetime_donor;
    Singlet_lifetime_acceptor = params.Singlet_lifetime_acceptor;
	Triplet_lifetime_donor = params.Triplet_lifetime_donor;
	Triplet_lifetime_acceptor = params.Triplet_lifetime_acceptor;
    R_singlet_hopping_donor = params.R_singlet_hopping_donor;
    R_singlet_hopping_acceptor = params.R_singlet_hopping_acceptor;
	R_triplet_hopping_donor = params.R_triplet_hopping_donor;
	R_triplet_hopping_acceptor = params.R_triplet_hopping_acceptor;
	Triplet_localization_donor = params.Triplet_localization_donor;
	Triplet_localization_acceptor = params.Triplet_localization_acceptor;
	Enable_FRET_triplet_annihilation = params.Enable_FRET_triplet_annihilation;
	R_exciton_exciton_annihilation_donor = params.R_exciton_exciton_annihilation_donor;
	R_exciton_exciton_annihilation_acceptor = params.R_exciton_exciton_annihilation_acceptor;
	R_exciton_polaron_annihilation_donor = params.R_exciton_polaron_annihilation_donor;
	R_exciton_polaron_annihilation_acceptor = params.R_exciton_polaron_annihilation_acceptor;
    FRET_cutoff = params.FRET_cutoff;
    E_exciton_binding_donor = params.E_exciton_binding_donor;
    E_exciton_binding_acceptor = params.E_exciton_binding_acceptor;
    R_exciton_dissociation_donor = params.R_exciton_dissociation_donor;
    R_exciton_dissociation_acceptor = params.R_exciton_dissociation_acceptor;
    Exciton_dissociation_cutoff = params.Exciton_dissociation_cutoff;
	R_exciton_isc_donor = params.R_exciton_isc_donor;
	R_exciton_isc_acceptor = params.R_exciton_isc_acceptor;
	R_exciton_risc_donor = params.R_exciton_risc_donor;
	R_exciton_risc_acceptor = params.R_exciton_risc_acceptor;
	E_exciton_ST_donor = params.E_exciton_ST_donor;
	E_exciton_ST_acceptor = params.E_exciton_ST_acceptor;
    // Polaron Parameters
    Enable_phase_restriction = params.Enable_phase_restriction;
    R_polaron_hopping_donor = params.R_polaron_hopping_donor;
    R_polaron_hopping_acceptor = params.R_polaron_hopping_acceptor;
    Polaron_localization_donor = params.Polaron_localization_donor;
    Polaron_localization_acceptor = params.Polaron_localization_acceptor;
    Enable_miller_abrahams = params.Enable_miller_abrahams;
    Enable_marcus = params.Enable_marcus;
    Reorganization_donor = params.Reorganization_donor;
    Reorganization_acceptor = params.Reorganization_acceptor;
    R_polaron_recombination = params.R_polaron_recombination;
    Polaron_hopping_cutoff = params.Polaron_hopping_cutoff;
    Enable_gaussian_polaron_delocalization = params.Enable_gaussian_polaron_delocalization;
    Polaron_delocalization_length = params.Polaron_delocalization_length;
    // Additional Lattice Parameters
    Homo_donor = params.Homo_donor;
    Lumo_donor = params.Lumo_donor;
    Homo_acceptor = params.Homo_acceptor;
    Lumo_acceptor = params.Lumo_acceptor;
    Enable_gaussian_dos = params.Enable_gaussian_dos;
    Energy_stdev_donor = params.Energy_stdev_donor;
    Energy_stdev_acceptor = params.Energy_stdev_acceptor;
    Enable_exponential_dos = params.Enable_exponential_dos;
    Energy_urbach_donor = params.Energy_urbach_donor;
    Energy_urbach_acceptor = params.Energy_urbach_acceptor;
	Enable_correlated_disorder = params.Enable_correlated_disorder;
	Disorder_correlation_length = params.Disorder_correlation_length;
	Enable_gaussian_kernel = params.Enable_gaussian_kernel;
	Enable_power_kernel = params.Enable_power_kernel;
	Power_kernel_exponent = params.Power_kernel_exponent;
    // Coulomb Calculation Parameters
    Dielectric_donor = params.Dielectric_donor;
    Dielectric_acceptor = params.Dielectric_acceptor;
    Coulomb_cutoff = params.Coulomb_cutoff;
    // Output files

    // Initialize Sites
    Site_OSC site;
    sites.assign(lattice.getNumSites(),site);
    // Initialize Film Architecture
    success = initializeArchitecture();
	if (!success) {
		Error_found = true;
		return false;
	}
	// Assign energies to each site in the sites vector
	reassignSiteEnergies();
    // Initialize Coulomb interactions lookup table
    double avgDielectric = (Dielectric_donor+Dielectric_acceptor)/2;
	double Unit_size = lattice.getUnitSize();
    int range = (int)ceil(intpow(Coulomb_cutoff/lattice.getUnitSize(),2));
    Coulomb_table.assign(range+1,0);
	for (int i = 1, imax = (int)Coulomb_table.size(); i<imax; i++) {
        Coulomb_table[i] = ((Coulomb_constant*Elementary_charge)/avgDielectric)/(1e-9*Unit_size*sqrt((double)i));
        if(Enable_gaussian_polaron_delocalization){
            Coulomb_table[i] *= erf((Unit_size*sqrt((double)i))/(Polaron_delocalization_length*sqrt(2)));
        }
    }
    // Initialize electrical potential vector
    E_potential.assign(lattice.getHeight(),0);
    for(int i=0;i<lattice.getHeight();i++){
        E_potential[i] = (Bias*lattice.getHeight()/(lattice.getHeight()+1))-(Bias/(lattice.getHeight()+1))*i;
    }
    // Initialize exciton creation event
    R_exciton_generation_donor = Exciton_generation_rate_donor*N_donor_sites*intpow(1e-7*lattice.getUnitSize(),3);
    R_exciton_generation_acceptor = Exciton_generation_rate_acceptor*N_acceptor_sites*intpow(1e-7*lattice.getUnitSize(),3);
    if(Enable_exciton_diffusion_test || Enable_IQE_test){
        isLightOn = true;
        exciton_creation_event.calculateExecutionTime(R_exciton_generation_donor+R_exciton_generation_acceptor,this);
        exciton_creation_it = addEvent(&exciton_creation_event);
    }
    else if(Enable_dynamics_test){
		isLightOn = false;
        // Initialize data structures
        double step_size = 1.0/(double)Dynamics_pnts_per_decade;
        int num_steps = (int)floor((log10(Dynamics_transient_end)-log10(Dynamics_transient_start))/step_size);
        transient_times.assign(num_steps,0);
        for(int i=0;i<(int)transient_times.size();i++){
            transient_times[i] = pow(10,log10(Dynamics_transient_start)+i*step_size);
        }
        transient_excitons.assign(num_steps,0);
        transient_electrons.assign(num_steps,0);
        transient_holes.assign(num_steps,0);
        // Create initial test excitons
        generateDynamicsExcitons();
    }
    else if(Enable_ToF_test){
		isLightOn = false;
        // Initialize data structures
        double step_size = 1.0/(double)ToF_pnts_per_decade;
        int num_steps = (int)floor((log10(ToF_transient_end)-log10(ToF_transient_start))/step_size);
        transient_times.assign(num_steps,0);
        for(int i=0;i<(int)transient_times.size();i++){
            transient_times[i] = pow(10,log10(ToF_transient_start)+i*step_size);
        }
        transient_counts.assign(num_steps,0);
        transient_velocities.assign(num_steps,0);
        transient_energies.assign(num_steps,0);
		Electron_extraction_data.assign(lattice.getLength()*lattice.getWidth(), 0);
		Hole_extraction_data.assign(lattice.getLength()*lattice.getWidth(), 0);
        // Create initial test polarons
        generateToFPolarons();
    }
	if (Enable_IQE_test) {
		Electron_extraction_data.assign(lattice.getLength()*lattice.getWidth(), 0);
		Hole_extraction_data.assign(lattice.getLength()*lattice.getWidth(), 0);
	}
	if (Error_found) {
		return false;
	}
	else {
		return true;
	}
}

double OSC_Sim::calculateCoulomb(const list<Polaron>::iterator polaron_it,const Coords& coords) const{
    static const double avgDielectric = (Dielectric_donor+Dielectric_acceptor)/2;
    static const double image_interactions = (Elementary_charge/(16*Pi*avgDielectric*Vacuum_permittivity))*1e9;
    double Energy = 0;
    double distance;
    int distance_sq_lat;
	bool charge = polaron_it->getCharge();
    static const int range = (int)ceil((Coulomb_cutoff/ lattice.getUnitSize())*(Coulomb_cutoff/ lattice.getUnitSize()));
    // Loop through electrons
    for(auto it=electrons.begin();it!=electrons.end();++it){
		if (!charge && it->getTag() == polaron_it->getTag()) {
			continue;
		}
        distance_sq_lat = lattice.calculateLatticeDistanceSquared(coords,it->getCoords());
        if(!(distance_sq_lat>range)){
            if(!charge){
                Energy += Coulomb_table[distance_sq_lat];
            }
            else{
                Energy -= Coulomb_table[distance_sq_lat];
            }
        }
    }
    // Loop through holes
    for(auto it=holes.begin();it!=holes.end();++it){
		if (charge && it->getTag() == polaron_it->getTag()) {
			continue;
		}
        distance_sq_lat = lattice.calculateLatticeDistanceSquared(coords,it->getCoords());
        if(!(distance_sq_lat>range)){
            if(charge){
                Energy += Coulomb_table[distance_sq_lat];
            }
            else{
                Energy -= Coulomb_table[distance_sq_lat];
            }
        }
    }
    // Add electrode image charge interactions
    if(!lattice.isZPeriodic() && !Enable_ToF_test){
        distance = lattice.getUnitSize()*((double)(lattice.getHeight()-coords.z)-0.5);
        if(!((distance-0.0001)>Coulomb_cutoff)){
            Energy -= image_interactions/distance;
        }
        distance = lattice.getUnitSize()*((double)(coords.z+1)-0.5);
        if(!((distance-0.0001)>Coulomb_cutoff)){
            Energy -= image_interactions/distance;
        }
    }
    return Energy;
}

double OSC_Sim::calculateCoulomb(const bool charge,const Coords& coords) const{
    static const double avgDielectric = (Dielectric_donor+Dielectric_acceptor)/2;
    static const double image_interactions = (Elementary_charge/(16*Pi*avgDielectric*Vacuum_permittivity))*1e9;
    double Energy = 0;
    double distance;
    int distance_sq_lat;
    static const int range = (int)ceil((Coulomb_cutoff/ lattice.getUnitSize())*(Coulomb_cutoff/ lattice.getUnitSize()));
    // Loop through electrons
    for(auto it=electrons.begin();it!=electrons.end();++it){
        distance_sq_lat = lattice.calculateLatticeDistanceSquared(coords,it->getCoords());
        if(!(distance_sq_lat>range)){
            if(!charge){
                Energy += Coulomb_table[distance_sq_lat];
            }
            else{
                Energy -= Coulomb_table[distance_sq_lat];
            }
        }
    }
    // Loop through holes
    for(auto it=holes.begin();it!=holes.end();++it){
        distance_sq_lat = lattice.calculateLatticeDistanceSquared(coords,it->getCoords());
        if(!(distance_sq_lat>range)){
            if(charge){
                Energy += Coulomb_table[distance_sq_lat];
            }
            else{
                Energy -= Coulomb_table[distance_sq_lat];
            }
        }
    }
    // Add electrode image charge interactions
    if(!lattice.isZPeriodic()){
        distance = lattice.getUnitSize()*((double)(lattice.getHeight()-coords.z)-0.5);
        if(!((distance-0.0001)>Coulomb_cutoff)){
            Energy -= image_interactions/distance;
        }
        distance = lattice.getUnitSize()*((double)(coords.z+1)-0.5);
        if(!((distance-0.0001)>Coulomb_cutoff)){
            Energy -= image_interactions/distance;
        }
    }
    return Energy;
}

double OSC_Sim::calculateDiffusionLength_avg() const{
    return vector_avg(diffusion_distances);
}

double OSC_Sim::calculateDiffusionLength_stdev() const{
    return vector_stdev(diffusion_distances);
}

vector<pair<double,double>> OSC_Sim::calculateDOSCorrelation(const double cutoff_radius) {
	int range = (int)ceil(cutoff_radius / lattice.getUnitSize());
	int size = (int)ceil(intpow(cutoff_radius / lattice.getUnitSize(), 2)) + 1;
	vector<double> sum_total(size, 0.0);
	vector<double> count_total(size, 0.0);
	vector<double> energies(sites.size());
	for (int n = 0, nmax = (int)sites.size(); n < nmax; n++) {
		Coords coords = lattice.getSiteCoords(n);
		energies[n] = getSiteEnergy(coords);
		for (int i = -range; i <= range; i++) {
			for (int j = -range; j <= range; j++) {
				for (int k = -range; k <= range; k++) {
					if (!lattice.checkMoveValidity(coords, i, j, k)) {
						continue;
					}
					Coords dest_coords;
					lattice.calculateDestinationCoords(coords, i, j, k, dest_coords);
					int distance_sq_lat = i*i + j*j + k*k;
					if (distance_sq_lat < size) {
						sum_total[distance_sq_lat] += getSiteEnergy(coords)*getSiteEnergy(dest_coords);
						count_total[distance_sq_lat] += 1.0;
					}
				}
			}
		}
	}
	double stdev = vector_stdev(energies);
	pair<double, double> data_pair;
	vector<pair<double, double>> correlation_data(1);
	correlation_data[0].first = 0.0;
	correlation_data[0].second = 1.0;
	for (int m = 1; m < size; m++) {
		if (count_total[m] > 0.1) {
			data_pair.first = lattice.getUnitSize()*sqrt((double)m);
			data_pair.second = sum_total[m] / ((count_total[m] - 1.0)*stdev*stdev);
			correlation_data.push_back(data_pair);
		}
	}
	return correlation_data;
}

vector<double> OSC_Sim::calculateMobilities(const vector<double>& transit_times) const {
	vector<double> mobilities = transit_times;
	for (int i = 0; i < (int)mobilities.size(); i++) {
		mobilities[i] = intpow(1e-7*lattice.getHeight()*lattice.getUnitSize(), 2) / (fabs(Bias)*transit_times[i]);
	}
	return mobilities;
}

double OSC_Sim::calculateMobility_avg() const{
    auto mobilities = transit_times;
    for(int i=0;i<(int)mobilities.size();i++){
        mobilities[i] = intpow(1e-7*lattice.getUnitSize()*lattice.getHeight(),2)/(fabs(Bias)*transit_times[i]);
    }
    return vector_avg(mobilities);
}

double OSC_Sim::calculateMobility_stdev() const{
    auto mobilities = transit_times;
    for(int i=0;i<(int)mobilities.size();i++){
        mobilities[i] = intpow(1e-7*lattice.getUnitSize()*lattice.getHeight(),2)/(fabs(Bias)*transit_times[i]);
    }
    return vector_stdev(mobilities);
}

vector<double> OSC_Sim::calculateTransitTimeDist(const vector<double>& data,const int counts) const{
    double step_size = 1.0/(double)ToF_pnts_per_decade;
    vector<double> dist(transient_times.size(),0);
    for(int i=0;i<(int)data.size();i++){
        for(int j=0;j<(int)transient_times.size();j++){
            if(data[i] > pow(10,log10(transient_times[j])-0.5*step_size) && data[i] < pow(10,log10(transient_times[j])+0.5*step_size)){
                dist[j] += 1.0/counts;
            }
        }
    }
    return dist;
}

double OSC_Sim::calculateTransitTime_avg() const{
    return vector_avg(transit_times);
}

double OSC_Sim::calculateTransitTime_stdev() const{
    return vector_stdev(transit_times);
}

Coords OSC_Sim::calculateExcitonCreationCoords(){
    static uniform_real_distribution<double> dist(0.0,R_exciton_generation_donor+R_exciton_generation_acceptor);
    double num = dist(gen);
    short type_target;
    if(num<R_exciton_generation_donor){
        type_target = 1;
    }
    else{
        type_target = 2;
    }
    Coords dest_coords;
    int N_tries = 0;
    while(N_tries<1000000){
        dest_coords = lattice.generateRandomCoords();
        if(isLoggingEnabled()){
            *Logfile << "Attempting to create exciton at " << dest_coords.x << "," << dest_coords.y << "," << dest_coords.z << "." << endl;
        }
        N_tries++;
        if(!lattice.isOccupied(dest_coords) && getSiteType(dest_coords)==type_target){
            return dest_coords;
        }
    }
    cout << getId() << ": Error! An empty site for exciton creation could not be found." << endl;
    Error_found = true;
    return dest_coords;
}

void OSC_Sim::calculateExcitonEvents(Object* object_ptr){
    const auto exciton_it = getExcitonIt(object_ptr);
    const Coords object_coords = exciton_it->getCoords();
    if(isLoggingEnabled()){
        *Logfile << "Calculating events for exciton " << exciton_it->getTag() << " at site " << object_coords.x << "," << object_coords.y << "," << object_coords.z << "." << endl;
    }
    Coords dest_coords;
	double E_delta, Coulomb_final;
	double rate = 0;
    int index;
    static const int range = (int)ceil( ((FRET_cutoff>Exciton_dissociation_cutoff) ? (FRET_cutoff):(Exciton_dissociation_cutoff))/ lattice.getUnitSize());
    static const int dim = (2*range+1);
    static vector<Exciton_Hop> hops_temp(dim*dim*dim);
    static vector<Exciton_Dissociation> dissociations_temp(dim*dim*dim);
	static vector<Exciton_Exciton_Annihilation> exciton_exciton_annihilations_temp(dim*dim*dim);
	static vector<Exciton_Polaron_Annihilation> exciton_polaron_annihilations_temp(dim*dim*dim);
    static vector<bool> hops_valid(dim*dim*dim,false);
    static vector<bool> dissociations_valid(dim*dim*dim,false);
	static vector<bool> exciton_exciton_annihilations_valid(dim*dim*dim, false);
	static vector<bool> exciton_polaron_annihilations_valid(dim*dim*dim, false);
	// pre-calculate a distances vector that contains the distances to nearby sites used for event execution time calculations
	// pre-calculate a isInRange vector that contains booleans to indicate if the nearby sites are within range for polaron events to be possible.
	static vector<double> distances(dim*dim*dim, 0.0);
	static vector<bool> isInDissRange(dim*dim*dim, false);
	static vector<bool> isInFRETRange(dim*dim*dim, false);
	static bool isInitialized = false;
	if (!isInitialized) {
		for (int i = -range; i <= range; i++) {
			for (int j = -range; j <= range; j++) {
				for (int k = -range; k <= range; k++) {
					index = (i + range)*dim*dim + (j + range)*dim + (k + range);
					distances[index] = lattice.getUnitSize()*sqrt((double)(i*i + j*j + k*k));
					if (!((distances[index] - 0.0001) > Exciton_dissociation_cutoff)) {
						isInDissRange[index] = true;
					}
					if (!((distances[index] - 0.0001) > FRET_cutoff)) {
						isInFRETRange[index] = true;
					}
				}
			}
		}
		isInitialized = true;
	}
	// Exciton hopping, dissociation, and annihilation events
    for(int i=-range;i<=range;i++){
        for(int j=-range;j<=range;j++){
            for(int k=-range;k<=range;k++){
                index = (i+range)*dim*dim+(j+range)*dim+(k+range);
				if (!isInDissRange[index] && !isInFRETRange[index]) {
					hops_valid[index] = false;
					dissociations_valid[index] = false;
					continue;
				}
                if(!lattice.checkMoveValidity(object_coords,i,j,k)){
                    hops_valid[index] = false;
                    dissociations_valid[index] = false;
                    continue;
                }
                lattice.calculateDestinationCoords(object_coords,i,j,k,dest_coords);
				// Annihilation events
				if (lattice.isOccupied(dest_coords)) {
					if (isInFRETRange[index]) {
						auto object_target_ptr = sites[lattice.getSiteIndex(dest_coords)].getObjectPtr();
						// Exciton-Exciton annihilation
						if (object_target_ptr->getName().compare(Exciton::name)) {
							exciton_exciton_annihilations_temp[index].setObjectPtr(object_ptr);
							exciton_exciton_annihilations_temp[index].setDestCoords(dest_coords);
							exciton_exciton_annihilations_temp[index].setObjectTargetPtr(object_target_ptr);
							// Exciton is starting from a donor site
							if (getSiteType(object_coords) == (short)1) {
								// Triplet Dexter mechanism
								if (!exciton_it->getSpin() && !Enable_FRET_triplet_annihilation) {
									exciton_exciton_annihilations_temp[index].calculateExecutionTime(R_exciton_exciton_annihilation_donor, Triplet_localization_donor, distances[index], this);
								}
								// FRET mechanism
								else {
									exciton_exciton_annihilations_temp[index].calculateExecutionTime(R_exciton_exciton_annihilation_donor, distances[index], this);
								}
							}
							// Exciton is starting from an acceptor site
							else {
								// Triplet Dexter mechanism
								if (!exciton_it->getSpin() && !Enable_FRET_triplet_annihilation) {
									exciton_exciton_annihilations_temp[index].calculateExecutionTime(R_exciton_exciton_annihilation_acceptor, Triplet_localization_acceptor, distances[index], this);
								}
								// FRET mechanism
								else {
									exciton_exciton_annihilations_temp[index].calculateExecutionTime(R_exciton_exciton_annihilation_acceptor, distances[index], this);
								}
							}
							exciton_exciton_annihilations_valid[index] = true;
						}
						else {
							exciton_exciton_annihilations_valid[index] = false;
						}
						// Exciton-Polaron annihilation
						if(sites[lattice.getSiteIndex(dest_coords)].getObjectPtr()->getName().compare(Polaron::name)) {
							exciton_polaron_annihilations_temp[index].setObjectPtr(object_ptr);
							exciton_polaron_annihilations_temp[index].setDestCoords(dest_coords);
							exciton_polaron_annihilations_temp[index].setObjectTargetPtr(object_target_ptr);
							// Exciton is starting from a donor site
							if (getSiteType(object_coords) == (short)1) {
								// Triplet Dexter mechanism
								if (!exciton_it->getSpin() && !Enable_FRET_triplet_annihilation) {
									exciton_polaron_annihilations_temp[index].calculateExecutionTime(R_exciton_polaron_annihilation_donor,Triplet_localization_donor, distances[index], this);
								}
								// FRET mechanism
								else {
									exciton_polaron_annihilations_temp[index].calculateExecutionTime(R_exciton_polaron_annihilation_donor, distances[index], this);
								}
							}
							// Exciton is starting from an acceptor site
							else {
								// Triplet Dexter mechanism
								if (!exciton_it->getSpin() && !Enable_FRET_triplet_annihilation) {
									exciton_polaron_annihilations_temp[index].calculateExecutionTime(R_exciton_polaron_annihilation_acceptor,Triplet_localization_acceptor, distances[index], this);
								}
								// FRET mechanism
								else {
									exciton_polaron_annihilations_temp[index].calculateExecutionTime(R_exciton_polaron_annihilation_acceptor, distances[index], this);
								}
							}
							exciton_polaron_annihilations_valid[index] = true;
						}
						else {
							exciton_polaron_annihilations_valid[index] = false;
						}
					}
				}
				// Dissociation and Hop events
				else {
					// Dissociation event
					if (getSiteType(object_coords) != getSiteType(dest_coords) && isInDissRange[index]) {
						dissociations_temp[index].setObjectPtr(object_ptr);
						dissociations_temp[index].setDestCoords(dest_coords);
						// Exciton is starting from a donor site
						if (getSiteType(object_coords) == (short)1) {
							Coulomb_final = calculateCoulomb(true, object_coords) + calculateCoulomb(false, dest_coords) - Coulomb_table[i*i + j*j + k*k];
							E_delta = (getSiteEnergy(dest_coords) - getSiteEnergy(object_coords)) - (Lumo_acceptor - Lumo_donor) + (Coulomb_final + E_exciton_binding_donor) + (E_potential[dest_coords.z] - E_potential[object_coords.z]);
							if (Enable_miller_abrahams) {
								dissociations_temp[index].calculateExecutionTime(R_exciton_dissociation_donor, Polaron_localization_donor, distances[index], E_delta, this);
							}
							else {
								dissociations_temp[index].calculateExecutionTime(R_exciton_dissociation_donor, Polaron_localization_donor, distances[index], E_delta, Reorganization_donor, this);
							}
						}
						// Exciton is starting from an acceptor site
						else {
							Coulomb_final = calculateCoulomb(false, object_coords) + calculateCoulomb(true, dest_coords) - Coulomb_table[i*i + j*j + k*k];
							E_delta = (getSiteEnergy(dest_coords) - getSiteEnergy(object_coords)) + (Homo_donor - Homo_acceptor) + (Coulomb_final + E_exciton_binding_donor) - (E_potential[dest_coords.z] - E_potential[object_coords.z]);
							if (Enable_miller_abrahams) {
								dissociations_temp[index].calculateExecutionTime(R_exciton_dissociation_acceptor, Polaron_localization_acceptor, distances[index], E_delta, this);
							}
							else {
								dissociations_temp[index].calculateExecutionTime(R_exciton_dissociation_acceptor, Polaron_localization_acceptor, distances[index], E_delta, Reorganization_acceptor, this);
							}
						}
						dissociations_valid[index] = true;
					}
					else {
						dissociations_valid[index] = false;
					}
					// Hop event
					if (getSiteType(object_coords) == getSiteType(dest_coords) && isInFRETRange[index]) {
						hops_temp[index].setObjectPtr(object_ptr);
						hops_temp[index].setDestCoords(dest_coords);
						E_delta = (getSiteEnergy(dest_coords) - getSiteEnergy(object_coords));
						// Singlet FRET hopping
						if (exciton_it->getSpin()) {
							if (getSiteType(object_coords) == (short)1) {
								hops_temp[index].calculateExecutionTime(R_singlet_hopping_donor, distances[index], E_delta, this);
							}
							else {
								hops_temp[index].calculateExecutionTime(R_singlet_hopping_acceptor, distances[index], E_delta, this);
							}
						}
						// Dexter hopping
						else {
							if (getSiteType(object_coords) == (short)1) {
								hops_temp[index].calculateExecutionTime(R_triplet_hopping_donor, Triplet_localization_donor, distances[index], E_delta, this);
							}
							else {
								hops_temp[index].calculateExecutionTime(R_triplet_hopping_donor, Triplet_localization_acceptor, distances[index], E_delta, this);
							}
						}
						hops_valid[index] = true;
					}
					else {
						hops_valid[index] = false;
					}
				}
            }
        }
    }
    // Exciton Recombination
    auto recombination_event_it = exciton_recombination_events.begin();
    advance(recombination_event_it,std::distance(excitons.begin(),exciton_it));
	if (exciton_it->getSpin()) {
		if (getSiteType(object_coords) == (short)1) {
			rate = 1.0 / Singlet_lifetime_donor;
		}
		else if (getSiteType(object_coords) == (short)2) {
			rate = 1.0 / Singlet_lifetime_acceptor;
		}
	}
	else {
		if (getSiteType(object_coords) == (short)1) {
			rate = 1.0 / Triplet_lifetime_donor;
		}
		else if (getSiteType(object_coords) == (short)2) {
			rate = 1.0 / Triplet_lifetime_acceptor;
		}
	}
    recombination_event_it->calculateExecutionTime(rate,this);
	// Exciton Intersystem Crossing
	auto intersystem_crossing_event_it = exciton_intersystem_crossing_events.begin();
	advance(intersystem_crossing_event_it, std::distance(excitons.begin(), exciton_it));
	// ISC
	if (exciton_it->getSpin()) {
		if (getSiteType(object_coords) == (short)1) {
			rate = R_exciton_isc_donor;
		}
		else if (getSiteType(object_coords) == (short)2) {
			rate = R_exciton_isc_acceptor;
		}
		intersystem_crossing_event_it->calculateExecutionTime(rate, 0.0, this);
	}
	// RISC
	else {
		if (getSiteType(object_coords) == (short)1) {
			intersystem_crossing_event_it->calculateExecutionTime(R_exciton_risc_donor, E_exciton_ST_donor, this);
		}
		else if (getSiteType(object_coords) == (short)2) {
			intersystem_crossing_event_it->calculateExecutionTime(R_exciton_risc_acceptor, E_exciton_ST_acceptor, this);
		}
	}
	// Determine the fastest valid exciton-exciton annihilation event
	bool No_exciton_exciton_annihilations_valid = true;
	auto exciton_exciton_annihilation_target_it = exciton_exciton_annihilations_temp.end();
	for (auto it = exciton_exciton_annihilations_temp.begin(); it != exciton_exciton_annihilations_temp.end(); ++it) {
		if (exciton_exciton_annihilations_valid[std::distance(exciton_exciton_annihilations_temp.begin(), it)] && (exciton_exciton_annihilation_target_it == exciton_exciton_annihilations_temp.end() || it->getExecutionTime()<exciton_exciton_annihilation_target_it->getExecutionTime())) {
			exciton_exciton_annihilation_target_it = it;
			No_exciton_exciton_annihilations_valid = false;
		}
	}
	// Determine the fastest valid exciton-polaron annihilation event
	bool No_exciton_polaron_annihilations_valid = true;
	auto exciton_polaron_annihilation_target_it = exciton_polaron_annihilations_temp.end();
	for (auto it = exciton_polaron_annihilations_temp.begin(); it != exciton_polaron_annihilations_temp.end(); ++it) {
		if (exciton_polaron_annihilations_valid[std::distance(exciton_polaron_annihilations_temp.begin(), it)] && (exciton_polaron_annihilation_target_it == exciton_polaron_annihilations_temp.end() || it->getExecutionTime()<exciton_polaron_annihilation_target_it->getExecutionTime())) {
			exciton_polaron_annihilation_target_it = it;
			No_exciton_polaron_annihilations_valid = false;
		}
	}
    // Determine the fastest valid hop event
    bool No_hops_valid = true;
    auto hop_target_it = hops_temp.end();
    for(auto it=hops_temp.begin();it!=hops_temp.end();++it){
        if(hops_valid[std::distance(hops_temp.begin(),it)] && (hop_target_it==hops_temp.end() || it->getExecutionTime()<hop_target_it->getExecutionTime())){
            hop_target_it = it;
            No_hops_valid = false;
        }
    }
    // Determine the fastest valid dissociation event
    bool No_dissociations_valid = true;
    auto dissociation_target_it = dissociations_temp.end();
    for(auto it=dissociations_temp.begin();it!=dissociations_temp.end();++it){
        if(dissociations_valid[std::distance(dissociations_temp.begin(),it)] && (dissociation_target_it==dissociations_temp.end() || it->getExecutionTime()<dissociation_target_it->getExecutionTime())){
            dissociation_target_it = it;
            No_dissociations_valid = false;
        }
    }
    // Determine fastest valid event
    int selection = 1;
    double best_time = recombination_event_it->getExecutionTime();
    if(!No_hops_valid && hop_target_it->getExecutionTime()<best_time){
        selection = 2;
        best_time = hop_target_it->getExecutionTime();
    }
    if(!No_dissociations_valid && dissociation_target_it->getExecutionTime()<best_time){
        selection = 3;
		best_time = dissociation_target_it->getExecutionTime();
    }
	if (!No_exciton_exciton_annihilations_valid && exciton_exciton_annihilation_target_it->getExecutionTime() < best_time) {
		selection = 4;
		best_time = exciton_exciton_annihilation_target_it->getExecutionTime();
	}
	if (!No_exciton_polaron_annihilations_valid && exciton_polaron_annihilation_target_it->getExecutionTime() < best_time) {
		selection = 5;
		best_time = exciton_polaron_annihilation_target_it->getExecutionTime();
	}
	if (intersystem_crossing_event_it->getExecutionTime() < best_time) {
		selection = 6;
		best_time = intersystem_crossing_event_it->getExecutionTime();
	}
    switch(selection){
        // Recombination event is fastest
        case 1:{
            setEvent(exciton_it->getEventIt(),&(*recombination_event_it));
            break;
        }
        // Hop event is fastest
        case 2:{
            auto hop_list_it = exciton_hop_events.begin();
            advance(hop_list_it,std::distance(excitons.begin(),exciton_it));
            *hop_list_it = *hop_target_it;
            setEvent(exciton_it->getEventIt(),&(*hop_list_it));
            break;
        }
        // Dissociation event is fastest
        case 3:{
            auto dissociation_list_it = exciton_dissociation_events.begin();
            advance(dissociation_list_it,std::distance(excitons.begin(),exciton_it));
            *dissociation_list_it = *dissociation_target_it;
            setEvent(exciton_it->getEventIt(),&(*dissociation_list_it));
            break;
        }
		// Exciton-exciton annihilation is fastest
		case 4: {
			auto exciton_exciton_annihilation_list_it = exciton_exciton_annihilation_events.begin();
			advance(exciton_exciton_annihilation_list_it, std::distance(excitons.begin(), exciton_it));
			*exciton_exciton_annihilation_list_it = *exciton_exciton_annihilation_target_it;
			setEvent(exciton_it->getEventIt(), &(*exciton_exciton_annihilation_list_it));
			break;
		}
		// Exciton-polaron annihilation is fastest
		case 5: {
			auto exciton_polaron_annihilation_list_it = exciton_polaron_annihilation_events.begin();
			advance(exciton_polaron_annihilation_list_it, std::distance(excitons.begin(), exciton_it));
			*exciton_polaron_annihilation_list_it = *exciton_polaron_annihilation_target_it;
			setEvent(exciton_it->getEventIt(), &(*exciton_polaron_annihilation_list_it));
			break;
		}
		// Intersystem crossing is fastest
		case 6: {
			setEvent(exciton_it->getEventIt(), &(*intersystem_crossing_event_it));
			break;
		}
        // No valid event found
        default:{
            cout << getId() << ": Error! No valid events could be calculated." << endl;
            Error_found = true;
            return;
        }
    }
}

void OSC_Sim::calculateObjectListEvents(const vector<Object*>& object_ptr_vec){
    if(isLoggingEnabled()){
        *Logfile << "Calculating events for " << object_ptr_vec.size() << " objects:" << endl;
    }
    for(auto it=object_ptr_vec.begin();it!=object_ptr_vec.end();++it){
        // If object is exciton
        if((*it)->getName().compare(Exciton::name)==0){
            calculateExcitonEvents(*it);
        }
        // If object is polaron
        else if((*it)->getName().compare(Polaron::name)==0){
            calculatePolaronEvents(*it);
        }
    }
}

void OSC_Sim::calculatePolaronEvents(Object* object_ptr){
    const auto polaron_it = getPolaronIt(object_ptr);
    const Coords object_coords = polaron_it->getCoords();
    if(isLoggingEnabled()){
        if(!polaron_it->getCharge()){
            *Logfile << "Calculating events for electron " << polaron_it->getTag() << " at site " << object_coords.x << "," << object_coords.y << "," << object_coords.z << "." << endl;
        }
        else{
            *Logfile << "Calculating events for hole " << polaron_it->getTag() << " at site " << object_coords.x << "," << object_coords.y << "," << object_coords.z << "." << endl;
        }
    }
	if (Enable_phase_restriction && !polaron_it->getCharge() && getSiteType(object_coords)==(short)1) {
		cout << "Error! Electron is on a donor site and should not be with phase restriction enabled." << endl;
		Error_found = true;
		return;
	}
	if (Enable_phase_restriction && polaron_it->getCharge() && getSiteType(object_coords) == (short)2) {
		cout << "Error! Hole is on an acceptor site and should not be with phase restriction enabled." << endl;
		Error_found = true;
		return;
	}
    Coords dest_coords;
    //double E_delta;
    int index;
	double E_site_i = getSiteEnergy(object_coords);
    double Coulomb_i = calculateCoulomb(polaron_it,object_coords);
    static const int range = (int)ceil(Polaron_hopping_cutoff/ lattice.getUnitSize());
    static const int dim = (2*range+1);
    static vector<Polaron_Hop> hops_temp(dim*dim*dim);
    static vector<Polaron_Recombination> recombinations_temp(dim*dim*dim);
    static vector<bool> hops_valid(dim*dim*dim,false);
    static vector<bool> recombinations_valid(dim*dim*dim,false);
	// pre-calculate a distances vector that contains the distances to nearby sites used for event execution time calculations
	// pre-calculate a isInRange vector that contains booleans to indicate if the nearby sites are within range for polaron events to be possible.
	static vector<double> distances(dim*dim*dim, 0.0);
	static vector<double> E_deltas(dim*dim*dim, 0.0);
	static vector<bool> isInRange(dim*dim*dim, false);
	static bool isInitialized = false;
	if (!isInitialized) {
		for (int i = -range; i <= range; i++) {
			for (int j = -range; j <= range; j++) {
				for (int k = -range; k <= range; k++) {
					index = (i + range)*dim*dim + (j + range)*dim + (k + range);
					distances[index] = lattice.getUnitSize()*sqrt((double)(i*i + j*j + k*k));
					if (!((distances[index] - 0.0001) > Polaron_hopping_cutoff)) {
						isInRange[index] = true;
					}
				}
			}
		}
		isInitialized = true;
	}
	// Calculate Polaron hopping and recombination events
    for(int i=-range;i<=range;i++){
        for(int j=-range;j<=range;j++){
            for(int k=-range;k<=range;k++){
				index = (i + range)*dim*dim + (j + range)*dim + (k + range);
				if (!isInRange[index]) {
					hops_valid[index] = false;
					recombinations_valid[index] = false;
					continue;
				}
				if (!lattice.checkMoveValidity(object_coords, i, j, k)) {
					hops_valid[index] = false;
					recombinations_valid[index] = false;
					continue;
				}
                lattice.calculateDestinationCoords(object_coords,i,j,k,dest_coords);
                // Recombination events
                // If destination site is occupied by a hole Polaron and the main Polaron is an electron, check for a possible recombination event
                if(lattice.isOccupied(dest_coords) && !polaron_it->getCharge() && siteContainsHole(dest_coords)){
                    if(getSiteType(object_coords)==(short)1){
                        recombinations_temp[index].calculateExecutionTime(R_polaron_recombination,Polaron_localization_donor,distances[index],0,this);
                    }
                    else if(getSiteType(object_coords)==(short)2){
                        recombinations_temp[index].calculateExecutionTime(R_polaron_recombination,Polaron_localization_acceptor,distances[index],0,this);
                    }
					recombinations_temp[index].setObjectPtr(object_ptr);
                    recombinations_temp[index].setDestCoords(dest_coords);
                    recombinations_temp[index].setObjectTargetPtr((*lattice.getSiteIt(dest_coords))->getObjectPtr());
                    recombinations_valid[index] = true;
                }
				else {
					recombinations_valid[index] = false;
				}
                // Hop events
                // If destination site is unoccupied and either phase restriction is disabled or the starting site and destination sites have the same type, check for a possible hop event
                if(!lattice.isOccupied(dest_coords) && (!Enable_phase_restriction || getSiteType(object_coords)==getSiteType(dest_coords))){
					E_deltas[index] = (getSiteEnergy(dest_coords) - E_site_i);
					E_deltas[index] += (calculateCoulomb(polaron_it,dest_coords)-Coulomb_i);
                    if(!polaron_it->getCharge()){
                        E_deltas[index] += (E_potential[dest_coords.z]-E_potential[object_coords.z]);
                    }
                    else{
                        E_deltas[index] -= (E_potential[dest_coords.z]-E_potential[object_coords.z]);
                    }
                    if(getSiteType(object_coords)==(short)1){
                        if(getSiteType(dest_coords)==(short)2){
                            if(!polaron_it->getCharge()){
                                E_deltas[index] -= (Lumo_acceptor-Lumo_donor);
                            }
                            else{
                                E_deltas[index] -= (Homo_acceptor-Homo_donor);
                            }
                        }
                        if(Enable_miller_abrahams){
                            hops_temp[index].calculateExecutionTime(R_polaron_hopping_donor,Polaron_localization_donor,distances[index],E_deltas[index],this);
                        }
                        else{
                            hops_temp[index].calculateExecutionTime(R_polaron_hopping_donor,Polaron_localization_donor,distances[index],E_deltas[index],Reorganization_donor,this);
                        }
                    }
                    else if(getSiteType(object_coords)==(short)2){
                        if(getSiteType(dest_coords)==(short)1){
                            if(!polaron_it->getCharge()){
                                E_deltas[index] -= (Lumo_donor-Lumo_acceptor);
                            }
                            else{
                                E_deltas[index] -= (Homo_donor-Homo_acceptor);
                            }
                        }
                        if(Enable_miller_abrahams){
                            hops_temp[index].calculateExecutionTime(R_polaron_hopping_acceptor,Polaron_localization_acceptor,distances[index],E_deltas[index],this);
                        }
                        else{
                            hops_temp[index].calculateExecutionTime(R_polaron_hopping_acceptor,Polaron_localization_acceptor,distances[index],E_deltas[index],Reorganization_acceptor,this);
                        }
                    }
					hops_temp[index].setObjectPtr(object_ptr);
					hops_temp[index].setDestCoords(dest_coords);
					hops_temp[index].setObjectTargetPtr(nullptr);
                    hops_valid[index] = true;
                }
				else {
					hops_valid[index] = false;
				}
            }
        }
    }
    // Calculate possible extraction event
    // Electrons are extracted at the bottom of the lattice (z=-1)
    // Holes are extracted at the top of the lattice (z=Height)
    bool No_extraction_valid = true;
    list<Polaron_Extraction>::iterator extraction_event_it;
    if(!Enable_dynamics_test || Enable_dynamics_extraction){
		double distance;
        // If electron, charge is false
        if(!polaron_it->getCharge()){
            distance = lattice.getUnitSize()*((double)(object_coords.z+1)-0.5);
            if(!((distance-0.0001)>Polaron_hopping_cutoff)){
                extraction_event_it = electron_extraction_events.begin();
                advance(extraction_event_it,std::distance(electrons.begin(),polaron_it));
                No_extraction_valid = false;
            }
        }
        // If hole, charge is true
        else{
            distance = lattice.getUnitSize()*((double)(lattice.getHeight()-object_coords.z)-0.5);
            if(!((distance-0.0001)>Polaron_hopping_cutoff)){
                extraction_event_it = hole_extraction_events.begin();
                advance(extraction_event_it,std::distance(holes.begin(),polaron_it));
                No_extraction_valid = false;
            }
        }
        if(!No_extraction_valid){
            if(getSiteType(object_coords)==(short)1){
                extraction_event_it->calculateExecutionTime(R_polaron_hopping_donor,distance,Polaron_localization_donor,0,this);
            }
            else if(getSiteType(object_coords)==(short)2){
                extraction_event_it->calculateExecutionTime(R_polaron_hopping_acceptor,distance,Polaron_localization_acceptor,0,this);
            }
        }
    }
    // Determine the fastest hop event
    bool No_hops_valid = true;
    auto hop_target_it = hops_temp.end();
	int n = 0;
    for(auto it=hops_temp.begin();it!=hops_temp.end();++it){
        if(hops_valid[n] && (hop_target_it==hops_temp.end() || it->getExecutionTime()<hop_target_it->getExecutionTime())){
            hop_target_it = it;
            No_hops_valid = false;
        }
		n++;
    }
    // Determine the fastest recombination event
    bool No_recombinations_valid = true;
    auto recombination_target_it = recombinations_temp.end();
	n = 0;
    for(auto it=recombinations_temp.begin();it!=recombinations_temp.end();++it){
        if(recombinations_valid[n] && (recombination_target_it==recombinations_temp.end() || it->getExecutionTime()<recombination_target_it->getExecutionTime())){
            recombination_target_it = it;
            No_recombinations_valid = false;
        }
		n++;
    }
    // If no valid event is found, return
    if(No_extraction_valid && No_hops_valid && No_recombinations_valid){
        setEvent(polaron_it->getEventIt(),nullptr);
        return;
    }
    // Determine the fastest valid event
    short selection = -1;
    double best_time = -1;
    if(!No_extraction_valid){
        selection = 1;
        best_time = extraction_event_it->getExecutionTime();
    }
    if(!No_hops_valid && (best_time<0 || hop_target_it->getExecutionTime()<best_time)){
        selection = 2;
        best_time = hop_target_it->getExecutionTime();
    }
    if(!No_recombinations_valid && (best_time<0 || recombination_target_it->getExecutionTime()<best_time)){
        selection = 3;
    }
    switch(selection){
        // Extraction event is fastest
        case 1:{
            setEvent(polaron_it->getEventIt(),&(*extraction_event_it));
            break;
        }
        // Hop event is fastest
        case 2:{
            list<Polaron_Hop>::iterator hop_list_it;
            // If electron, charge is false
            if(!polaron_it->getCharge()){
                hop_list_it = electron_hop_events.begin();
                advance(hop_list_it,std::distance(electrons.begin(),polaron_it));
            }
            // If hole, charge is true
            else{
                hop_list_it = hole_hop_events.begin();
                advance(hop_list_it,std::distance(holes.begin(),polaron_it));
            }
            *hop_list_it = *hop_target_it;
            setEvent(polaron_it->getEventIt(),&(*hop_list_it));
            break;
        }
        // Recombination event is fastest
        case 3:{
            list<Polaron_Recombination>::iterator recombination_list_it;
            // If electron, charge is false
            if(!polaron_it->getCharge()){
                recombination_list_it = polaron_recombination_events.begin();
                advance(recombination_list_it,std::distance(electrons.begin(),polaron_it));
            }
            // If hole, charge is true
            else{
                cout << getId() << ": Error! Only electrons can initiate polaron recombination." << endl;
                Error_found = true;
                return;
            }
            *recombination_list_it = *recombination_target_it;
            setEvent(polaron_it->getEventIt(),&(*recombination_list_it));
            break;
        }
        // No valid event found
        default:{
            cout << getId() << ": Error! No valid events could be calculated." << endl;
            Error_found = true;
            return;
        }
    }
}

bool OSC_Sim::checkFinished() const{
    if(Error_found){
        cout << getId() << ": An error has been detected and the simulation will now end." << endl;
        return true;
    }
    if(Enable_exciton_diffusion_test){
        return (N_excitons_recombined==N_tests);
    }
    if(Enable_dynamics_test){
        if(getTime()>Dynamics_transient_end || (N_excitons==0 && N_electrons==0 && N_holes==0)){
            return true;
        }
        return false;
    }
    if(Enable_ToF_test){
        return ((N_electrons==0 && N_electrons_collected>=N_tests) || (N_holes==0 && N_holes_collected>=N_tests) || N_electrons_created>2*N_tests || N_holes_created>2*N_tests);
    }
    if(Enable_IQE_test){
        if(N_excitons_created==N_tests && N_excitons==0 && N_electrons==0 && N_holes==0){
            return true;
        }
        if(getTime()>IQE_time_cutoff){
            return true;
        }
        return false;
    }
    cout << getId() << ": Error checking simulation finish conditions.  The simulation will now end." << endl;
    return true;
}

bool OSC_Sim::checkParameters(const Parameters_OPV& params) const{
	// Check lattice parameters and other general parameters
	if (!(params.Length>0) || !(params.Width>0) || !(params.Height>0)) {
		cout << "Error! All lattice dimensions must be greater than zero." << endl;
		return false;
	}
	if (!(params.Unit_size>0)) {
		cout << "Error! The lattice unit size must be greater than zero." << endl;
		return false;
	}
	if (!(params.Temperature>0)) {
		cout << "Error! The temperature must be greater than zero." << endl;
		return false;
	}
	if (!(params.Recalc_cutoff > 0)) {
		cout << "Error! The event recalculation cutoff radius must be greater than zero." << endl;
		return false;
	}
	if (params.Recalc_cutoff<params.FRET_cutoff) {
		cout << "Error! The event recalculation cutoff radius must not be less than the FRET cutoff radius." << endl;
		return false;
	}
	if (params.Recalc_cutoff<params.Polaron_hopping_cutoff) {
		cout << "Error! The event recalculation cutoff radius must not be less than the polaron hopping cutoff radius." << endl;
		return false;
	}
	if (params.Recalc_cutoff<params.Exciton_dissociation_cutoff) {
		cout << "Error! The event recalculation cutoff radius must not be less than the exciton dissociation cutoff radius." << endl;
		return false;
	}
	// Check film architecture parameters
	if (params.Enable_bilayer && params.Thickness_donor + params.Thickness_acceptor != params.Height) {
		cout << "Error! When using the bilayer film architecture, the sum of the donor and the acceptor thicknesses must equal the lattice height." << endl;
		return false;
	}
	// Possible device architectures:
	// Neat
	// Bilayer
	// Random Blend
	// Import morphology
	int N_architectures_enabled = 0;
	if (params.Enable_neat) {
		N_architectures_enabled++;
	}
	if (params.Enable_bilayer) {
		N_architectures_enabled++;
	}
	if (params.Enable_random_blend) {
		N_architectures_enabled++;
	}
	if (params.Enable_import_morphology) {
		N_architectures_enabled++;
	}
	if (N_architectures_enabled == 0) {
		cout << "Error! A film architecture must be enabled." << endl;
		return false;
	}
	if (N_architectures_enabled>1) {
		cout << "Error! Only one film architecture can be enabled." << endl;
		return false;
	}
	// Check test parameters
	if (params.Enable_ToF_test && params.Enable_bilayer) {
		cout << "Error! The bilayer film architecture cannot be used with the time-of-flight charge transport test." << endl;
		return false;
	}
	if (params.Enable_ToF_test && params.Enable_periodic_z) {
		cout << "Error! The z-direction periodic boundary must be disabled in order to run the time-of-flight charge transport test." << endl;
		return false;
	}
	if (params.Enable_IQE_test && params.Enable_periodic_z) {
		cout << "Error! The z-direction periodic boundary must be disabled in order to run the internal quantum efficiency test." << endl;
		return false;
	}
	if (params.Enable_neat && params.Enable_IQE_test) {
		cout << "Error! The neat film architecture cannot be used with the internal quantum efficiency test." << endl;
		return false;
	}
	if (!(params.N_tests>0)) {
		cout << "Error! The number of tests must be greater than zero." << endl;
		return false;
	}
	// Possible simulation tests:
	// Exciton diffusion test
	// ToF test
	// IQE test
	// Dynamics test
	int N_tests_enabled = 0;
	if (params.Enable_exciton_diffusion_test)
		N_tests_enabled++;
	if (params.Enable_ToF_test)
		N_tests_enabled++;
	if (params.Enable_IQE_test)
		N_tests_enabled++;
	if (params.Enable_dynamics_test)
		N_tests_enabled++;
	if (N_tests_enabled>1) {
		cout << "Error! Only one test can be enabled." << endl;
		return false;
	}
	if (N_tests_enabled == 0) {
		cout << "Error! One of the tests must be enabled." << endl;
		return false;
	}
	// Check exciton parameters
	if (params.Exciton_generation_rate_donor < 0 || params.Exciton_generation_rate_acceptor < 0) {
		cout << "Error! The exciton generation rate of the donor and acceptor must not be negative." << endl;
		return false;
	}
	if (!(params.Singlet_lifetime_donor > 0) || !(params.Singlet_lifetime_acceptor > 0)) {
		cout << "Error! The singlet exciotn lifetime of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.Triplet_lifetime_donor > 0) || !(params.Triplet_lifetime_acceptor > 0)) {
		cout << "Error! The triplet exciton lifetime of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.R_singlet_hopping_donor > 0) || !(params.R_singlet_hopping_acceptor > 0)) {
		cout << "Error! The singlet exciton hopping rate of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.R_triplet_hopping_donor > 0) || !(params.R_triplet_hopping_acceptor > 0)) {
		cout << "Error! The triplet exciton hopping rate of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.Triplet_localization_donor > 0) || !(params.Triplet_localization_acceptor > 0)) {
		cout << "Error! The triplet exciton localization parameter of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.R_exciton_exciton_annihilation_donor > 0) || !(params.R_exciton_exciton_annihilation_acceptor > 0)) {
		cout << "Error! The exciton-exciton annihilation rate of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.R_exciton_polaron_annihilation_donor > 0) || !(params.R_exciton_polaron_annihilation_acceptor > 0)) {
cout << "Error! The exciton-polaron annihilation rate of the donor and acceptor must be greater than zero." << endl;
return false;
	}
	if (!(params.FRET_cutoff > 0)) {
		cout << "Error! The FRET cutoff radius must be greater than zero." << endl;
		return false;
	}
	if (params.E_exciton_binding_donor < 0 || params.E_exciton_binding_acceptor < 0) {
		cout << "Error! The exciton binding energy of the donor and acceptor cannot be negative." << endl;
		return false;
	}
	if (!(params.R_exciton_dissociation_donor > 0) || !(params.R_exciton_dissociation_acceptor > 0)) {
		cout << "Error! The exciton dissociation rate of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.Exciton_dissociation_cutoff > 0)) {
		cout << "Error! The exciton dissociation cutoff radius must be greater than zero." << endl;
		return false;
	}
	if (!(params.R_exciton_isc_donor > 0) || !(params.R_exciton_isc_acceptor > 0)) {
		cout << "Error! The exciton intersystem crossing rate of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.R_exciton_risc_donor > 0) || !(params.R_exciton_risc_acceptor > 0)) {
		cout << "Error! The exciton reverse intersystem crossing rate of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (!(params.E_exciton_ST_donor > 0) || !(params.E_exciton_ST_acceptor > 0)) {
		cout << "Error! The exciton singlet-triplet splitting energy of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	// Check polaron parameters
	if (!(params.R_polaron_hopping_donor > 0) || !(params.R_polaron_hopping_acceptor > 0)) {
		cout << "Error! The polaron hopping rate of the donor and accpetor must be greater than zero." << endl;
		return false;
	}
	if (!(params.Polaron_localization_donor > 0) || !(params.Polaron_localization_acceptor > 0)) {
		cout << "Error! The polaron localization parameter of the donor and acceptor must be greater than zero." << endl;
		return false;
	}
	if (params.Enable_miller_abrahams && params.Enable_marcus) {
		cout << "Error! The Miller-Abrahams and the Marcus polaron hopping models cannot both be enabled." << endl;
		return false;
	}
	if (!params.Enable_miller_abrahams && !params.Enable_marcus) {
		cout << "Error! Either the Miller-Abrahams or the Marcus polaron hopping model must be enabled." << endl;
		return false;
	}
	if (params.Reorganization_donor < 0 || params.Reorganization_acceptor < 0) {
		cout << "Error! The polaron reorganization energy of the donor and acceptor must not be negative." << endl;
		return false;
	}
	if (!(params.R_polaron_recombination > 0)) {
		cout << "Error! The polaron recombination rate must be greater than zero." << endl;
		return false;
	}
	if (!(params.Polaron_hopping_cutoff > 0)) {
		cout << "Error! The polaron hopping cutoff radius must be greater than zero." << endl;
		return false;
	}
	if (!(params.Polaron_delocalization_length > 0)) {
		cout << "Error! The polaron delocalization length must be greater than zero." << endl;
		return false;
	}
	// Check lattice site parameters
	if (params.Homo_donor < 0 || params.Lumo_donor < 0) {
		cout << "Error! The HOMO and LUMO parameters of the donor must not be negative." << endl;
		return false;
	}
	if (params.Homo_acceptor < 0 || params.Lumo_acceptor < 0) {
		cout << "Error! The HOMO and LUMO parameters of the acceptor must not be negative." << endl;
		return false;
	}
	if (params.Enable_gaussian_dos && params.Enable_exponential_dos) {
		cout << "Error! The Gaussian and exponential disorder models cannot both be enabled." << endl;
		return false;
	}
	if (params.Enable_gaussian_dos && (params.Energy_stdev_donor < 0 || params.Energy_stdev_acceptor < 0)) {
		cout << "Error! When using the Gaussian disorder model, the standard deviation cannot be negative." << endl;
		return false;
	}
	if (params.Enable_exponential_dos && (params.Energy_urbach_donor < 0 || params.Energy_urbach_acceptor < 0)) {
		cout << "Error! When using the exponential disorder model, the Urbach energy cannot be negative." << endl;
		return false;
	}
	int kernel_counter = 0;
	if (params.Enable_correlated_disorder && params.Enable_gaussian_kernel) {
		kernel_counter++;
	}
	if (params.Enable_correlated_disorder && params.Enable_power_kernel) {
		kernel_counter++;
	}
	if (params.Enable_correlated_disorder && kernel_counter!=1) {
		cout << "Error! When using the correlated disorder model, you must enable one and only one kernel. You have " << kernel_counter << " kernels enabled." << endl;
		return false;
	}
	if (params.Enable_correlated_disorder && params.Enable_power_kernel && !(params.Power_kernel_exponent==-1 || params.Power_kernel_exponent==-2) ) {
		cout << "Error! When using the correlated disorder model with the power kernel, the power kernel exponent must be either -1 or -2." << endl;
		return false;
	}
	if (params.Enable_correlated_disorder && (params.Disorder_correlation_length < 0.999 || params.Disorder_correlation_length > 3.001)) {
		cout << "Error! When using the correlated disorder model, the disorder correlation length must be in the range between 1.0 and 3.0." << endl;
		return false;
	}
	if (params.Enable_correlated_disorder && !params.Enable_neat && params.Energy_stdev_donor != params.Energy_stdev_acceptor) {
		cout << "Error! When using the correlated disorder model, the standard deviation of the donor and acceptor Gaussian DOS must be equal." << endl;
		return false;
	}
	if (params.Enable_correlated_disorder && !params.Enable_gaussian_dos) {
		cout << "Error! The correlated disorder model can only be used with a Gaussian density of states." << endl;
		return false;
	}
	// Check Coulomb interaction parameters
	if (!(params.Coulomb_cutoff > 0)) {
		cout << "Error! The Coulomb cutoff radius must be greater than zero." << endl;
		return false;
	}
	if (!(params.Dielectric_donor > 0) || !(params.Dielectric_acceptor > 0)) {
		cout << "Error! The dielectric constant of the donor and the acceptor must be greater than zero." << endl;
		return false;
	}
	return true;
}

void OSC_Sim::createCorrelatedDOS(const double correlation_length) {
	int range;
	double stdev, percent_diff;
	double distance_max = 0;
	double scale_factor = 1;
	double Unit_size = lattice.getUnitSize();
	if (Enable_gaussian_kernel) {
		distance_max = 1 + 1.8*correlation_length;
		scale_factor = -0.1 - 1.21*pow(correlation_length, -2.87);
	}
	if (Enable_power_kernel && Power_kernel_exponent == -1) {
		distance_max = 1 + 4.5*correlation_length;
		scale_factor = 0.7 + 3.1*pow(correlation_length, -1.55);
	}
	if (Enable_power_kernel && Power_kernel_exponent == -2) {
		distance_max = 1 + 2.3*correlation_length;
		scale_factor = -0.4 + 2.2*pow(correlation_length, -0.74);
		scale_factor = pow(scale_factor, 2);
	}
	// Create and calculates distances and range check vectors
	range = (int)ceil(distance_max / Unit_size);
	int dim = 2 * range + 1;
	int vec_size = dim*dim*dim;
	vector<double> distances(vec_size, 0.0);
	vector<bool> isInRange(vec_size, false);
	vector<int> distance_indices(vec_size, 0);
	for (int i = -range; i <= range; i++) {
		for (int j = -range; j <= range; j++) {
			for (int k = -range; k <= range; k++) {
				int index = (i + range)*dim*dim + (j + range)*dim + (k + range);
				distance_indices[index] = i*i + j*j + k*k;
				distances[index] = Unit_size*sqrt((double)(i*i + j*j + k*k));
				if (i == 0 && j == 0 && k == 0) {
					distances[index] = -1.0;
				}
				else if ((distances[index] - 1e-6) < distance_max) {
					isInRange[index] = true;
				}
			}
		}
	}
	// Impart correlation
	vector<double> new_energies((int)sites.size(), 0.0);
	vector<double> isAble(vec_size, 0.0);
	vector<double> energies_temp(vec_size, 0.0);
	vector<double> counts((int)ceil((distance_max / Unit_size)*(distance_max / Unit_size)) + 1, 0.0);
	for (int n = 0, nmax = (int)sites.size(); n < nmax; n++) {
		isAble.assign(vec_size, 0.0);
		energies_temp.assign(vec_size, 0.0);
		Coords coords = lattice.getSiteCoords(n);
		// Get nearby site energies and determine if able
		#pragma loop(hint_parallel(2))
		#pragma loop(ivdep)
		for (int i = -range; i <= range; i++) {
			for (int j = -range; j <= range; j++) {
				for (int k = -range; k <= range; k++) {
					if (!lattice.checkMoveValidity(coords, i, j, k)) {
						continue;
					}
					Coords dest_coords;
					lattice.calculateDestinationCoords(coords, i, j, k, dest_coords);
					int index = (i + range)*dim*dim + (j + range)*dim + (k + range);
					if (isInRange[index]) {
						energies_temp[index] = getSiteEnergy(dest_coords);
						isAble[index] = 1.0;
					}
				}
			}
		}
		if (Enable_gaussian_kernel) {
			for (int m = 0; m < vec_size; m++) {
				energies_temp[m] = isAble[m] * energies_temp[m] * exp(scale_factor * distances[m] * distances[m]);
			}
		}
		if (Enable_power_kernel && Power_kernel_exponent == -1) {
			for (int m = 0; m < vec_size; m++) {
				energies_temp[m] = isAble[m] * energies_temp[m] / (scale_factor * distances[m]);
			}
		}
		if (Enable_power_kernel && Power_kernel_exponent == -2) {
			for (int m = 0; m < vec_size; m++) {
				energies_temp[m] = isAble[m] * energies_temp[m] / (scale_factor * distances[m] * distances[m]);
			}
		}
		// Normalize energies by site count
		counts.assign((int)ceil((distance_max / Unit_size)*(distance_max / Unit_size)) + 1, 0.0);
		for (int m = 0; m < vec_size; m++) {
			if (isAble[m] > 0.1 && distance_indices[m] < (int)counts.size()) {
				counts[distance_indices[m]] += 1.0;
			}
		}
		for (int m = 0; m < vec_size; m++) {
			if (isAble[m] > 0.1 && distance_indices[m] < (int)counts.size()) {
				energies_temp[m] /= counts[distance_indices[m]];
			}
		}
		new_energies[n] = accumulate(energies_temp.begin(), energies_temp.end(), getSiteEnergy(coords));
	}
	// Normalize energies to reach desired disorder
	stdev = vector_stdev(new_energies);
	percent_diff = (stdev - Energy_stdev_donor) / Energy_stdev_donor;
	double norm_factor = 1 + percent_diff;
	for (int n = 0; n < (int)sites.size(); n++) {
		new_energies[n] /= norm_factor;
	}
	// Assign new energies to the sites
	for (int n = 0; n < (int)sites.size(); n++) {
		sites[n].setEnergy(new_energies[n]);
	}
	// Calculate the correlation function
	DOS_correlation_data = calculateDOSCorrelation(distance_max);
}

bool OSC_Sim::createImportedMorphology(){
    string file_info;
    string line;
    stringstream ss;
    Coords coords;
    short type = 0;
    int length,width,height;
    int site_count = 0;
	bool isV3 = false;
	bool isV4 = false;
    // Get input morphology file information
    getline(*Morphology_file,line);
    file_info = line;
    // Parse file info
	if (file_info.find("Ising_OPV v3.2 - compressed format") != string::npos) {
		isV3 = true;
	}
	else if (file_info.find("Ising_OPV v4.0") != string::npos && file_info.find("compressed")!=string::npos && file_info.find("uncompressed") == string::npos) {
		isV4 = true;
	}
    else {
        cout << getId() << ": Error! Morphology file format not recognized. Only compressed morphologies created using Ising_OPV v3.2 and v4.0 are currently supported." << endl;
        Error_found = true;
        return false;
    }
    getline(*Morphology_file,line);
    length = atoi(line.c_str());
    getline(*Morphology_file,line);
    width = atoi(line.c_str());
    getline(*Morphology_file,line);
    height = atoi(line.c_str());
    if(lattice.getLength()!=length || lattice.getWidth()!=width || lattice.getHeight()!=height){
        cout << getId() << ": Error! Morphology lattice dimensions do not match the lattice dimensions defined in the parameter file." << endl;
        Error_found = true;
        return false;
    }
	if (isV3) {
		// Skip 3 lines (domain size1, domain size2, blend ratio)
		getline(*Morphology_file, line);
		getline(*Morphology_file, line);
		getline(*Morphology_file, line);
	}
	else if (isV4) {
		// skip boundary conditions
		getline(*Morphology_file, line);
		getline(*Morphology_file, line);
		getline(*Morphology_file, line);
		// number of site types
		getline(*Morphology_file, line);
		int N_types = atoi(line.c_str());
		// skip domain size and mix fraction lines
		for (int i = 0; i < 2 * N_types; i++) {
			getline(*Morphology_file, line);
		}
	}
    // Begin parsing morphology site data
	for (int x = 0; x < lattice.getLength(); x++) {
		for (int y = 0; y < lattice.getWidth(); y++) {
			for (int z = 0; z < lattice.getHeight(); z++) {
				if (site_count == 0) {
					if (!(*Morphology_file).good()) {
						cout << "Error parsing file.  End of file reached before expected." << endl;
						Error_found = true;
						return false;
					}
					getline(*Morphology_file, line);
					type = (short)atoi(line.substr(0, 1).c_str());
					site_count = atoi(line.substr(1).c_str());
				}
				coords.setXYZ(x, y, z);
				sites[lattice.getSiteIndex(coords)].setType(type);
				if (type == (short)1) {
					N_donor_sites++;
				}
				else if (type == (short)2) {
					N_acceptor_sites++;
				}
				site_count--;
			}
		}
	}
    // Check for unassigned sites
    for(auto it=sites.begin();it!=sites.end();++it){
        if(it->getType()==(short)0){
            cout << getId() << ": Error! Unassigned site found after morphology import. Check the morphology file for errors." << endl;
            Error_found = true;
            return false;
        }
    }
    return true;
}

void OSC_Sim::deleteObject(Object* object_ptr){
    if(object_ptr->getName().compare(Exciton::name)==0){
        auto exciton_it = getExcitonIt(object_ptr);
        // Remove the object from Simulation
        removeObject(object_ptr);
        // Locate corresponding recombination event
        auto recombination_list_it = exciton_recombination_events.begin();
        advance(recombination_list_it,std::distance(excitons.begin(),exciton_it));
        // Locate corresponding hop event
        auto hop_list_it = exciton_hop_events.begin();
        advance(hop_list_it,std::distance(excitons.begin(),exciton_it));
        // Locate corresponding dissociation event
        auto dissociation_list_it = exciton_dissociation_events.begin();
        advance(dissociation_list_it,std::distance(excitons.begin(),exciton_it));
		// Locate corresponding exciton-exciton annihilation event
		auto exciton_exciton_annihilation_list_it = exciton_exciton_annihilation_events.begin();
		advance(exciton_exciton_annihilation_list_it, std::distance(excitons.begin(), exciton_it));
		// Locate corresponding exciton-polaron annihilation event
		auto exciton_polaron_annihilation_list_it = exciton_polaron_annihilation_events.begin();
		advance(exciton_polaron_annihilation_list_it, std::distance(excitons.begin(), exciton_it));
		// Locate corresponding exciton intersystem crossing event
		auto intersystem_crossing_list_it = exciton_intersystem_crossing_events.begin();
		advance(intersystem_crossing_list_it, std::distance(excitons.begin(), exciton_it));
        // Delete exciton
        excitons.erase(exciton_it);
        // Delete exciton recombination event
        exciton_recombination_events.erase(recombination_list_it);
        // Delete exciton hop event
        exciton_hop_events.erase(hop_list_it);
        // Delete exciton dissociation event
        exciton_dissociation_events.erase(dissociation_list_it);
		// Delete exciton-exciton annihilation event
		exciton_exciton_annihilation_events.erase(exciton_exciton_annihilation_list_it);
		// Delete exciton-exciton annihilation event
		exciton_polaron_annihilation_events.erase(exciton_polaron_annihilation_list_it);
		// Delete exciton intersystem crossing event
		exciton_intersystem_crossing_events.erase(intersystem_crossing_list_it);
    }
    else if(object_ptr->getName().compare(Polaron::name)==0){
        auto polaron_it = getPolaronIt(object_ptr);
        // Remove the object from Simulation
        removeObject(object_ptr);
        // Electron
        if(!(polaron_it->getCharge())){
            // Locate corresponding recombination event
            auto recombination_list_it = polaron_recombination_events.begin();
            advance(recombination_list_it,std::distance(electrons.begin(),polaron_it));
            // Locate corresponding hop event
            auto hop_list_it = electron_hop_events.begin();
            advance(hop_list_it,std::distance(electrons.begin(),polaron_it));
            // Locate corresponding dissociation event
            auto extraction_list_it = electron_extraction_events.begin();
            advance(extraction_list_it,std::distance(electrons.begin(),polaron_it));
            // Delete electron
            electrons.erase(polaron_it);
            // Delete polaron recombination event
            polaron_recombination_events.erase(recombination_list_it);
            // Delete electron hop event
            electron_hop_events.erase(hop_list_it);
            // Delete electron extraction event
            electron_extraction_events.erase(extraction_list_it);
        }
        // Hole
        else{
            // Locate corresponding hop event
            auto hop_list_it = hole_hop_events.begin();
            advance(hop_list_it,std::distance(holes.begin(),polaron_it));
            // Locate corresponding dissociation event
            auto extraction_list_it = hole_extraction_events.begin();
            advance(extraction_list_it,std::distance(holes.begin(),polaron_it));
            // Delete hole
            holes.erase(polaron_it);
            // Delete hole hop event
            hole_hop_events.erase(hop_list_it);
            // Delete hole extraction event
            hole_extraction_events.erase(extraction_list_it);
        }
    }
}

bool OSC_Sim::executeExcitonCreation(){
    // Determine coordinates for the new exciton
    const Coords coords_new = calculateExcitonCreationCoords();
    generateExciton(coords_new);
    // Find all nearby excitons and calculate their events
    auto neighbors = findRecalcNeighbors(coords_new);
    calculateObjectListEvents(neighbors);
    // Calculate next exciton creation event
    exciton_creation_event.calculateExecutionTime(R_exciton_generation_donor+R_exciton_generation_acceptor,this);
    return true;
}

bool OSC_Sim::executeExcitonDissociation(const list<Event*>::iterator event_it){
    // Get event info
    Coords coords_initial = (((*event_it)->getObjectPtr()))->getCoords();
    Coords coords_dest = (*event_it)->getDestCoords();
    // Delete exciton and its events
    deleteObject((*event_it)->getObjectPtr());
    // Generate new electron and hole
    int tag = (N_electrons_created>N_holes_created) ? (N_electrons_created+1) : (N_holes_created+1);
    if(getSiteType(coords_dest)==(short)2){
        generateHole(coords_initial,tag);
        generateElectron(coords_dest,tag);
    }
    else{
        generateElectron(coords_initial,tag);
        generateHole(coords_dest,tag);
    }
    // Update counters
    N_excitons--;
    N_excitons_dissociated++;
    // Find all nearby objects
    auto neighbors = findRecalcNeighbors(coords_initial);
    auto neighbors2 = findRecalcNeighbors(coords_dest);
    neighbors.insert(neighbors.end(),neighbors2.begin(),neighbors2.end());
    removeDuplicates(neighbors);
    // Calculate events for all nearby objects
    calculateObjectListEvents(neighbors);
    return true;
}

bool OSC_Sim::executeExcitonExcitonAnnihilation(const list<Event*>::iterator event_it) {
	// Get event info
	auto object_ptr = (*event_it)->getObjectPtr();
	int exciton_tag = object_ptr->getTag();
	int target_tag = ((*event_it)->getObjectTargetPtr())->getTag();
	Coords coords_initial = object_ptr->getCoords();
	Coords coords_dest = (*event_it)->getDestCoords();
	// Check for triplet-triplet annihilation
	if (!getExcitonIt(object_ptr)->getSpin() && !getExcitonIt((*event_it)->getObjectTargetPtr())->getSpin()) {
		// Target triplet exciton becomes a singlet exciton
		getExcitonIt((*event_it)->getObjectTargetPtr())->flipSpin();
	}
	// delete exciton and its events
	deleteObject((*event_it)->getObjectPtr());
	// Update exciton counters
	N_excitons--;
	N_exciton_exciton_annihilations++;
	// Log event
	if (isLoggingEnabled()) {
		*Logfile << "Exciton " << exciton_tag << " annihilated at site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z;
		*Logfile << " with exciton " << target_tag << " at " << coords_dest.x << "," << coords_dest.y << "," << coords_dest.z << "." << endl;
	}
	// Find all nearby objects
	auto neighbors = findRecalcNeighbors(coords_initial);
	auto neighbors2 = findRecalcNeighbors(coords_dest);
	neighbors.insert(neighbors.end(), neighbors2.begin(), neighbors2.end());
	removeDuplicates(neighbors);
	// Calculate events for all nearby objects
	calculateObjectListEvents(neighbors);
	return true;
}

bool OSC_Sim::executeExcitonPolaronAnnihilation(const list<Event*>::iterator event_it) {
	// Get event info
	auto object_ptr = (*event_it)->getObjectPtr();
	int exciton_tag = object_ptr->getTag();
	int target_tag = ((*event_it)->getObjectTargetPtr())->getTag();
	Coords coords_initial = object_ptr->getCoords();
	Coords coords_dest = (*event_it)->getDestCoords();
	// delete exciton and its events
	deleteObject((*event_it)->getObjectPtr());
	// Update exciton counters
	N_excitons--;
	N_exciton_polaron_annihilations++;
	// Log event
	if (isLoggingEnabled()) {
		*Logfile << "Exciton " << exciton_tag << " annihilated at site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z;
		*Logfile << " with polaron " << target_tag << " at " << coords_dest.x << "," << coords_dest.y << "," << coords_dest.z << "." << endl;
	}
	// Find all nearby objects
	auto neighbors = findRecalcNeighbors(coords_initial);
	auto neighbors2 = findRecalcNeighbors(coords_dest);
	neighbors.insert(neighbors.end(), neighbors2.begin(), neighbors2.end());
	removeDuplicates(neighbors);
	// Calculate events for all nearby objects
	calculateObjectListEvents(neighbors);
	return true;
}

bool OSC_Sim::executeExcitonHop(const list<Event*>::iterator event_it) {
	if (lattice.isOccupied((*event_it)->getDestCoords())) {
		cout << getId() << ": Error! Exciton hop cannot be executed. Destination site is already occupied." << endl;
		Error_found = true;
		return false;
	}
	else {
		if (isLoggingEnabled()) {
			*Logfile << "Exciton " << ((*event_it)->getObjectPtr())->getTag() << " hopping to site " << (*event_it)->getDestCoords().x << "," << (*event_it)->getDestCoords().y << "," << (*event_it)->getDestCoords().z << "." << endl;
		}
		return executeObjectHop(event_it);
	}
}

bool OSC_Sim::executeExcitonIntersystemCrossing(const list<Event*>::iterator event_it) {
	// Get event info
	int exciton_tag = ((*event_it)->getObjectPtr())->getTag();
	Coords coords_initial = ((*event_it)->getObjectPtr())->getCoords();
	auto exciton_it = getExcitonIt((*event_it)->getObjectPtr());
	bool spin_i = exciton_it->getSpin();
	// Execute spin flip
	exciton_it->flipSpin();
	// Update exciton counters
	if (spin_i) {
		N_exciton_intersystem_crossings++;
	}
	else {
		N_exciton_reverse_intersystem_crossings++;
	}
	// Log event
	if (isLoggingEnabled()) {
		if (spin_i) {
			*Logfile << "Singlet exciton " << exciton_tag << " at site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z << " has become a triplet exciton." << endl;
		}
		else {
			*Logfile << "Triplet exciton " << exciton_tag << " at site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z << " has become a singlet exciton." << endl;
		}
	}
	// Find all nearby excitons and calculate their events
	auto neighbors = findRecalcNeighbors(coords_initial);
	calculateObjectListEvents(neighbors);
	return true;
}

bool OSC_Sim::executeExcitonRecombine(const list<Event*>::iterator event_it) {
	// Get event info
	int exciton_tag = ((*event_it)->getObjectPtr())->getTag();
	Coords coords_initial = ((*event_it)->getObjectPtr())->getCoords();
	// Output diffusion distance
	if (Enable_exciton_diffusion_test) {
		diffusion_distances.push_back(((*event_it)->getObjectPtr())->calculateDisplacement());
	}
	// delete exciton and its events
	deleteObject((*event_it)->getObjectPtr());
	// Update exciton counters
	N_excitons--;
	N_excitons_recombined++;
	// Log event
	if (isLoggingEnabled()) {
		*Logfile << "Exciton " << exciton_tag << " recombined at site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z << "." << endl;
	}
	// Find all nearby excitons and calculate their events
	auto neighbors = findRecalcNeighbors(coords_initial);
	calculateObjectListEvents(neighbors);
	return true;
}

bool OSC_Sim::executeNextEvent() {
	if (Enable_IQE_test) {
		if (isLightOn && N_excitons_created == N_tests) {
			removeEvent(&exciton_creation_event);
			isLightOn = false;
		}
	}
	if (Enable_ToF_test) {
		// Perform ToF test analysis
		updateToFData();
		// If none of the polarons can move or have reached the transient cutoff
		if (getN_events() == 0 || (getTime() - ToF_creation_time) > ToF_transient_end) {
			// Remove any remaining polarons
			while ((int)electrons.size() > 0) {
				N_electrons--;
				deleteObject(&electrons.front());
			}
			while ((int)holes.size() > 0) {
				N_holes--;
				deleteObject(&holes.front());
			}
		}
		// Check if new ToF polarons need to be created
		if (N_holes == 0 && N_electrons == 0 && !checkFinished()) {
			generateToFPolarons();
		}
		if (checkFinished()) {
			return true;
		}
	}
    auto event_it = chooseNextEvent();
    if(*event_it==nullptr){
        cout << getId() << ": Error! The simulation has no events to execute." << endl;
        Error_found = true;
        return false;
    }
    string event_name = (*event_it)->getName();
    if(isLoggingEnabled()){
        *Logfile << "Executing " << event_name << " event" << endl;
    }
    // Update simulation time
    updateTime((*event_it)->getExecutionTime());
    // Update dynamics data
    if(Enable_dynamics_test){
        updateDynamicsData();
    }
    // Execute the chosen event
    if(event_name.compare(Exciton_Creation::name)==0){
        return executeExcitonCreation();
    }
    else if(event_name.compare(Exciton_Hop::name)==0){
        return executeExcitonHop(event_it);
    }
    else if(event_name.compare(Exciton_Recombination::name)==0){
        return executeExcitonRecombine(event_it);
    }
    else if(event_name.compare(Exciton_Dissociation::name)==0){
        return executeExcitonDissociation(event_it);
    }
    else if(event_name.compare(Exciton_Exciton_Annihilation::name)==0){
        return executeExcitonExcitonAnnihilation(event_it);
    }
    else if(event_name.compare(Exciton_Polaron_Annihilation::name)==0){
        return executeExcitonPolaronAnnihilation(event_it);
    }
	else if (event_name.compare(Exciton_Intersystem_Crossing::name) == 0) {
		return executeExcitonIntersystemCrossing(event_it);
	}
    else if(event_name.compare(Polaron_Hop::name)==0){
        return executePolaronHop(event_it);
    }
    else if(event_name.compare(Polaron_Recombination::name)==0){
        return executePolaronRecombination(event_it);
    }
    else if(event_name.compare(Polaron_Extraction::name)==0){
        return executePolaronExtraction(event_it);
    }
    else{
        //error
        cout << getId() << ": Error! Valid event not found when calling executeNextEvent" << endl;
        Error_found = true;
        return false;
    }
}

bool OSC_Sim::executeObjectHop(const list<Event*>::iterator event_it) {
	// Get event info
	auto object_ptr = (*event_it)->getObjectPtr();
	Coords coords_initial = object_ptr->getCoords();
	Coords coords_dest = (*event_it)->getDestCoords();
	// Move the object in the Simulation
	moveObject((*event_it)->getObjectPtr(), coords_dest);
	// Find all nearby objects and calculate their events
	auto neighbors = findRecalcNeighbors(coords_initial);
	auto neighbors2 = findRecalcNeighbors(coords_dest);
	neighbors.insert(neighbors.end(), neighbors2.begin(), neighbors2.end());
	removeDuplicates(neighbors);
	calculateObjectListEvents(neighbors);
	return true;
}

bool OSC_Sim::executePolaronExtraction(const list<Event*>::iterator event_it){
    // Get event info
	auto polaron_it = getPolaronIt((*event_it)->getObjectPtr());
	bool charge = polaron_it->getCharge();
    int polaron_tag = ((*event_it)->getObjectPtr())->getTag();
    Coords coords_initial = ((*event_it)->getObjectPtr())->getCoords();
    // Save transit time and extraction location info
    if(Enable_ToF_test){
        transit_times.push_back(getTime()-((*event_it)->getObjectPtr())->getCreationTime());
    }
	if (Enable_ToF_test || Enable_IQE_test) {
		if (!charge) {
			Electron_extraction_data[lattice.getWidth()*coords_initial.x + coords_initial.y]++;
		}
		else {
			Hole_extraction_data[lattice.getWidth()*coords_initial.x + coords_initial.y]++;
		}
	}
    // Delete polaron and its events
    deleteObject((*event_it)->getObjectPtr());
    // Update polaron counters
    if(!charge){
        N_electrons_collected++;
        N_electrons--;
    }
    else{
        N_holes_collected++;
        N_holes--;
    }
    // Log event
    if(isLoggingEnabled()){
        if(!charge){
            *Logfile << "Electron " << polaron_tag << " was extracted from site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z << "." << endl;
        }
        else{
            *Logfile << "Hole " << polaron_tag << " was extracted from site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z << "." << endl;
        }
    }
    if(Enable_ToF_test && N_holes==0 && N_electrons==0 && !checkFinished()){
        generateToFPolarons();
    }
    else{
        // Find all nearby objects and calculate their events
        auto neighbors = findRecalcNeighbors(coords_initial);
        calculateObjectListEvents(neighbors);
    }
    return true;
}

bool OSC_Sim::executePolaronHop(const list<Event*>::iterator event_it){
    if(lattice.isOccupied((*event_it)->getDestCoords())){
        cout << getId() << ": Error! Polaron hop cannot be executed. Destination site is already occupied." << endl;
        Error_found = true;
        return false;
    }
    else{
        auto polaron_it = getPolaronIt((*event_it)->getObjectPtr());
        // Log event
        if(isLoggingEnabled()){
            if(!polaron_it->getCharge()){
                *Logfile << "Electron " << polaron_it->getTag() << " hopping to site " << (*event_it)->getDestCoords().x << "," << (*event_it)->getDestCoords().y << "," << (*event_it)->getDestCoords().z << "." << endl;
            }
            else{
                *Logfile << "Hole " << polaron_it->getTag() << " hopping to site " << (*event_it)->getDestCoords().x << "," << (*event_it)->getDestCoords().y << "," << (*event_it)->getDestCoords().z << "." << endl;
            }
        }
		//cout << getSiteEnergy((*event_it)->getDestCoords()) << endl;
        return executeObjectHop(event_it);
    }
}

bool OSC_Sim::executePolaronRecombination(const list<Event*>::iterator event_it){
    // Get event info
    auto object_ptr = (*event_it)->getObjectPtr();
    int polaron_tag = object_ptr->getTag();
    int target_tag = ((*event_it)->getObjectTargetPtr())->getTag();
    Coords coords_initial = object_ptr->getCoords();
    Coords coords_dest = (*event_it)->getDestCoords();
    // Delete polarons and their events
    deleteObject((*event_it)->getObjectTargetPtr());
    deleteObject(object_ptr);
    // Update polaron counters
    N_electrons_recombined++;
    N_holes_recombined++;
    N_electrons--;
    N_holes--;
    if(polaron_tag==target_tag){
        N_geminate_recombinations++;
    }
    else{
        N_bimolecular_recombinations++;
    }
    // Log event
    if(isLoggingEnabled()){
        *Logfile << "Electron " << polaron_tag << " at site " << coords_initial.x << "," << coords_initial.y << "," << coords_initial.z << " recombined with hole " << target_tag << " at site " << coords_dest.x << "," << coords_dest.y << "," << coords_dest.z << "." << endl;
    }
    // Find all nearby objects
    auto neighbors = findRecalcNeighbors(coords_initial);
    auto neighbors2 = findRecalcNeighbors(coords_dest);
    neighbors.insert(neighbors.end(),neighbors2.begin(),neighbors2.end());
    removeDuplicates(neighbors);
    // Calculate events for all nearby objects
    calculateObjectListEvents(neighbors);
    return true;
}

void OSC_Sim::generateExciton(const Coords& coords){
    // Create the new exciton and add it to the simulation
    Exciton exciton_new(getTime(),N_excitons_created+1,coords);
	exciton_new.setSpin(true); // Generated exciton is in singlet state
    excitons.push_back(exciton_new);
	Object* object_ptr = &excitons.back();
    addObject(object_ptr);
    // Add placeholder events to the corresponding lists
    Exciton_Hop hop_event;
    exciton_hop_events.push_back(hop_event);
    Exciton_Recombination recombination_event;
    recombination_event.setObjectPtr(object_ptr);
    exciton_recombination_events.push_back(recombination_event);
    Exciton_Dissociation dissociation_event;
    exciton_dissociation_events.push_back(dissociation_event);
	Exciton_Exciton_Annihilation exciton_exciton_annihilation_event;
	exciton_exciton_annihilation_events.push_back(exciton_exciton_annihilation_event);
	Exciton_Polaron_Annihilation exciton_polaron_annihilation_event;
	exciton_polaron_annihilation_events.push_back(exciton_polaron_annihilation_event);
	Exciton_Intersystem_Crossing intersystem_crossing_event;
	exciton_intersystem_crossing_events.push_back(intersystem_crossing_event);
    // Update exciton counters
    if(getSiteType(coords)==(short)1){
        N_excitons_created_donor++;
    }
    else{
        N_excitons_created_acceptor++;
    }
    N_excitons_created++;
    N_excitons++;
    // Log event
    if(isLoggingEnabled()){
        *Logfile << "Created exciton " << exciton_new.getTag() << " at site " << coords.x << "," << coords.y << "," << coords.z << "." << endl;
    }
}

void OSC_Sim::generateElectron(const Coords& coords,int tag=0){
    if(tag==0){
        tag = N_electrons_created+1;
    }
    // Create the new electron and add it to the simulation
    Polaron electron_new(getTime(),tag,coords,false);
    electrons.push_back(electron_new);
	Object* object_ptr = &electrons.back();
    addObject(object_ptr);
    // Add placeholder events to the corresponding lists
    Polaron_Hop hop_event;
    electron_hop_events.push_back(hop_event);
    Polaron_Recombination recombination_event;
    recombination_event.setObjectPtr(object_ptr);
    polaron_recombination_events.push_back(recombination_event);
    Polaron_Extraction extraction_event;
    extraction_event.setObjectPtr(object_ptr);
    electron_extraction_events.push_back(extraction_event);
    // Update exciton counters
    N_electrons_created++;
    N_electrons++;
    // Log event
    if(isLoggingEnabled()){
        *Logfile << "Created electron " << electron_new.getTag() << " at site " << coords.x << "," << coords.y << "," << coords.z << "." << endl;
    }
}

void OSC_Sim::generateHole(const Coords& coords,int tag=0){
    if(tag==0){
        tag = N_holes_created+1;
    }
    // Create the new hole and add it to the simulation
    Polaron hole_new(getTime(),tag,coords,true);
    holes.push_back(hole_new);
	Object* object_ptr = &holes.back();
    addObject(object_ptr);
    // Add placeholder events to the corresponding lists
    Polaron_Hop hop_event;
    hole_hop_events.push_back(hop_event);
    Polaron_Extraction extraction_event;
    extraction_event.setObjectPtr(object_ptr);
    hole_extraction_events.push_back(extraction_event);
    // Update exciton counters
    N_holes_created++;
    N_holes++;
    // Log event
    if(isLoggingEnabled()){
        *Logfile << "Created hole " << hole_new.getTag() << " at site " << coords.x << "," << coords.y << "," << coords.z << "." << endl;
    }
}

void OSC_Sim::generateDynamicsExcitons(){
    int num = 0;
    Coords coords;
    int initial_excitons = (int)ceil(Dynamics_initial_exciton_conc*intpow(1e-7*lattice.getUnitSize(),3)*lattice.getLength()*lattice.getWidth()*lattice.getHeight());
    cout << getId() << ": Generating " << initial_excitons << " initial excitons." << endl;
    while(num<initial_excitons){
        coords = calculateExcitonCreationCoords();
        generateExciton(coords);
        num++;
    }
	N_transient_cycles++;
    auto object_its = getAllObjectPtrs();
    calculateObjectListEvents(object_its);
}

void OSC_Sim::generateToFPolarons(){
    Coords coords;
	// Reassign site energies
	if (N_electrons_collected > 0 || N_holes_collected > 0) {
		reassignSiteEnergies();
	}
    // Create electrons at the top plane of the lattice
    if(!ToF_polaron_type){
        coords.z = lattice.getHeight()-1;
    }
    // Create holes at the bottom plane of the lattice
    else{
        coords.z = 0;
    }
	ToF_polaron_tags.assign(ToF_initial_polarons, -1);
    ToF_positions_prev.assign(ToF_initial_polarons,coords.z);
	ToF_times_prev.assign(ToF_initial_polarons, getTime());
    ToF_energies_prev.assign(ToF_initial_polarons,0);
	ToF_creation_time = getTime();
	ToF_index_prev = -1;
	int num = 0;
    while(num<ToF_initial_polarons){
        coords.x = lattice.generateRandomX();
        coords.y = lattice.generateRandomY();
        // If the site is already occupied, pick a new site
        if(lattice.isOccupied(coords)){
            continue;
        }
        // If phase restriction is enabled, electrons cannot be created on donor sites
        else if(Enable_phase_restriction && !ToF_polaron_type && getSiteType(coords)==(short)1){
            continue;
        }
        // If phase restriction is enabled, holes cannot be created on acceptor sites
        else if(Enable_phase_restriction && ToF_polaron_type && getSiteType(coords)==(short)2){
            continue;
        }
        else if(!ToF_polaron_type){
            generateElectron(coords);
			ToF_polaron_tags[num] = electrons.back().getTag();
        }
        else{
            generateHole(coords);
			ToF_polaron_tags[num] = holes.back().getTag();
        }
		ToF_energies_prev[num] = getSiteEnergy(coords);
		// donor
		if (getSiteType(coords) == (short)1) {
			//electron
			if (!ToF_polaron_type) {
				ToF_energies_prev[num] += -Lumo_donor;
			}
			//hole
			else {
				ToF_energies_prev[num] += -Homo_donor;
			}
		}
		// acceptor
		else {
			//electron
			if (!ToF_polaron_type) {
				ToF_energies_prev[num] += -Lumo_acceptor;
			}
			//hole
			else {
				ToF_energies_prev[num] += -Homo_acceptor;
			}
		}
        num++;
    }
	N_transient_cycles++;
    auto object_its = getAllObjectPtrs();
    calculateObjectListEvents(object_its);
}

vector<double> OSC_Sim::getDiffusionData() const {
    return diffusion_distances;
}

vector<int> OSC_Sim::getDynamicsTransientExcitons() const {
    return transient_excitons;
}

vector<int> OSC_Sim::getDynamicsTransientElectrons() const {
    return transient_electrons;
}

vector<pair<double, double>> OSC_Sim::getDOSCorrelationData() const {
	return DOS_correlation_data;
}

vector<int> OSC_Sim::getDynamicsTransientHoles() const {
    return transient_holes;
}

vector<double> OSC_Sim::getDynamicsTransientTimes() const {
    return transient_times;
}

list<Exciton>::iterator OSC_Sim::getExcitonIt(const Object* object_ptr){
    for(auto it=excitons.begin();it!=excitons.end();++it){
        if(object_ptr->getTag()==it->getTag()){
            return it;
        }
    }
	cout << "Error! Exciton iterator could not be located." << endl;
	Error_found = true;
	return excitons.end();
}

int OSC_Sim::getN_bimolecular_recombinations() const {
    return N_bimolecular_recombinations;
}

int OSC_Sim::getN_electrons_collected() const {
    return N_electrons_collected;
}

int OSC_Sim::getN_electrons_created() const {
    return N_electrons_created;
}

int OSC_Sim::getN_electrons_recombined() const {
    return N_electrons_recombined;
}

int OSC_Sim::getN_excitons_created() const {
    return N_excitons_created;
}

int OSC_Sim::getN_excitons_created(const short site_type) const {
    if(site_type==(short)1){
        return N_excitons_created_donor;
    }
    else{
        return N_excitons_created_acceptor;
    }
}

int OSC_Sim::getN_excitons_dissociated() const {
return N_excitons_dissociated;
}

int OSC_Sim::getN_excitons_recombined() const {
	return N_excitons_recombined;
}

int OSC_Sim::getN_geminate_recombinations() const {
	return N_geminate_recombinations;
}

int OSC_Sim::getN_holes_collected() const {
	return N_holes_collected;
}

int OSC_Sim::getN_holes_created() const {
	return N_holes_created;
}

int OSC_Sim::getN_holes_recombined() const {
	return N_holes_recombined;
}

int OSC_Sim::getN_transient_cycles() const {
	return N_transient_cycles;
}

list<Polaron>::iterator OSC_Sim::getPolaronIt(const Object* object_ptr) {
	if (object_ptr->getName().compare(Polaron::name) == 0) {
		// electrons
		if (!(static_cast<const Polaron*>(object_ptr)->getCharge())) {
			for (auto it = electrons.begin(); it != electrons.end(); ++it) {
				if (object_ptr->getTag() == it->getTag()) {
					return it;
				}
			}
		}
		// holes
		else {
			for (auto it = holes.begin(); it != holes.end(); ++it) {
				if (object_ptr->getTag() == it->getTag()) {
					return it;
				}
			}
		}
	}
	cout << "Error! Polaron iterator could not be located." << endl;
	Error_found = true;
	return electrons.end();
}

vector<double> OSC_Sim::getSiteEnergies(const short site_type) const {
	vector<double> energies;
	for(int i = 0; i < lattice.getNumSites(); i++) {
		if (sites[i].getType() == site_type) {
			energies.push_back(sites[i].getEnergy());
		}
	}
	return energies;
	//if (site_type == 1) {
	//	return site_energies_donor;
	//}
	//else if (site_type == 2) {
	//	return site_energies_acceptor;
	//}
	//else {
	//	vector<double> empty_vec(0);
	//	cout << "Error! Invalid site type specified while getting the site energies." << endl;
	//	return empty_vec;
	//}
}

double OSC_Sim::getSiteEnergy(const Coords& coords) const {
	return sites[lattice.getSiteIndex(coords)].getEnergy();
}

short OSC_Sim::getSiteType(const Coords& coords) const {
	return sites[lattice.getSiteIndex(coords)].getType();
}

vector<string> OSC_Sim::getChargeExtractionMap(const bool charge) const {
	vector<string> output_data(lattice.getLength()*lattice.getWidth() + 1);
	stringstream ss;
	int x, y;
	output_data[0] = "X-Position,Y-Position,Extraction Probability";
	if (!charge) {
		for (int i = 1; i < (int)Electron_extraction_data.size(); i++) {
			x = i / lattice.getWidth();
			y = i % lattice.getWidth();
			ss << x << "," << y << "," << (double)Electron_extraction_data[i] / (double)(N_electrons_collected);
			output_data[i] = ss.str();
			ss.str("");
		}
	}
	else {
		for (int i = 1; i < (int)Hole_extraction_data.size(); i++) {
			x = i / lattice.getWidth();
			y = i % lattice.getWidth();
			ss << x << "," << y << "," << (double)Hole_extraction_data[i] / (double)(N_holes_collected);
			output_data[i] = ss.str();
			ss.str("");
		}
	}
	return output_data;
}

vector<int> OSC_Sim::getToFTransientCounts() const {
	return transient_counts;
}

vector<double> OSC_Sim::getToFTransientEnergies() const {
	return transient_energies;
}

vector<double> OSC_Sim::getToFTransientTimes() const {
    return transient_times;
}

vector<double> OSC_Sim::getToFTransientVelocities() const {
    return transient_velocities;
}

vector<double> OSC_Sim::getTransitTimeData() const {
	return transit_times;
}

bool OSC_Sim::initializeArchitecture() {
	bool success;
	N_donor_sites = 0;
	N_acceptor_sites = 0;
	if (Enable_neat) {
		N_donor_sites = lattice.getNumSites();
		N_acceptor_sites = 0;
		for (auto it = sites.begin(); it != sites.end(); ++it) {
			it->setType(1);
		}
	}
	else if (Enable_bilayer) {
		Coords coords;
		for (int x = 0; x < lattice.getLength(); x++) {
			for (int y = 0; y < lattice.getWidth(); y++) {
				for (int z = 0; z < lattice.getHeight(); z++) {
					coords.setXYZ(x, y, z);
					if (z < Thickness_acceptor) {
						sites[lattice.getSiteIndex(coords)].setType(2);
						N_acceptor_sites++;
					}
					else {
						sites[lattice.getSiteIndex(coords)].setType(1);
						N_donor_sites++;
					}
				}
			}
		}
	}
	else if (Enable_random_blend) {
		vector<short> site_types;
		site_types.assign(lattice.getNumSites(), 1);
		for (int i = 0; i < (int)lattice.getNumSites()*Acceptor_conc; i++) {
			site_types[i] = 2;
			N_acceptor_sites++;
		}
		N_donor_sites = lattice.getNumSites() - N_acceptor_sites;
		shuffle(site_types.begin(), site_types.end(), gen);
		for (int i = 0; i < (int)sites.size(); i++) {
			sites[i].setType(site_types[i]);
		}
	}
	else if (Enable_import_morphology) {
		success = createImportedMorphology();
		if (!success) {
			return false;
		}
	}
	// Send the site pointers to the Lattice object
	vector<Site*> site_ptrs((int)sites.size());
	for (int i = 0; i < (int)sites.size(); i++){
		site_ptrs[i] = &sites[i];
	}
	lattice.setSitePointers(site_ptrs);
	return true;
}

void OSC_Sim::outputStatus(){
    cout << getId() << ": Time = " << getTime() << " seconds.\n";
    if(Enable_ToF_test){
        if(!ToF_polaron_type){
            cout << getId() << ": " << N_electrons_collected << " out of " << N_electrons_created << " electrons have been collected and " << getN_events_executed() << " events have been executed.\n";
            cout << getId() << ": There are currently " << N_electrons << " electrons in the lattice:\n";
            for(auto it=electrons.begin();it!=electrons.end();++it){
                cout << getId() << ": Electron " << it->getTag() << " is at " << it->getCoords().x << "," << it->getCoords().y << "," << it->getCoords().z << ".\n";
            }
        }
        else{
            cout << getId() << ": " << N_holes_collected << " out of " << N_holes_created << " holes have been collected and " << getN_events_executed() << " events have been executed.\n";
            cout << getId() << ": There are currently " << N_holes << " holes in the lattice:\n";
            for(auto it=holes.begin();it!=holes.end();++it){
                cout << getId() << ": Hole " << it->getTag() << " is at " << it->getCoords().x << "," << it->getCoords().y << "," << it->getCoords().z << ".\n";
            }
        }
    }
    if(Enable_exciton_diffusion_test){
        cout << getId() << ": " << N_excitons_created << " excitons have been created and " << getN_events_executed() << " events have been executed.\n";
        cout << getId() << ": There are currently " << N_excitons << " excitons in the lattice:\n";
        for(auto it=excitons.begin();it!=excitons.end();++it){
            cout << getId() << ": Exciton " << it->getTag() << " is at " << it->getCoords().x << "," << it->getCoords().y << "," << it->getCoords().z << ".\n";
        }
    }
    if(Enable_IQE_test || Enable_dynamics_test){
        cout << getId() << ": " << N_excitons_created << " excitons have been created and " << getN_events_executed() << " events have been executed.\n";
        cout << getId() << ": There are currently " << N_excitons << " excitons in the lattice:\n";
        for(auto it=excitons.begin();it!=excitons.end();++it){
            cout << getId() << ": Exciton " << it->getTag() << " is at " << it->getCoords().x << "," << it->getCoords().y << "," << it->getCoords().z << ".\n";
        }
        cout << getId() << ": There are currently " << N_electrons << " electrons in the lattice:\n";
        for(auto it=electrons.begin();it!=electrons.end();++it){
            cout << getId() << ": Electron " << it->getTag() << " is at " << it->getCoords().x << "," << it->getCoords().y << "," << it->getCoords().z << ".\n";
        }
        cout << getId() << ": There are currently " << N_holes << " holes in the lattice:\n";
        for(auto it=holes.begin();it!=holes.end();++it){
            cout << getId() << ": Hole " << it->getTag() << " is at " << it->getCoords().x << "," << it->getCoords().y << "," << it->getCoords().z << ".\n";
        }
    }
    cout.flush();
}

void OSC_Sim::reassignSiteEnergies() {
	if (Enable_gaussian_dos) {
		site_energies_donor.assign(N_donor_sites, 0);
		site_energies_acceptor.assign(N_acceptor_sites, 0);
		createGaussianDOSVector(site_energies_donor, 0, Energy_stdev_donor, gen);
		createGaussianDOSVector(site_energies_acceptor, 0, Energy_stdev_acceptor, gen);
	}
	else if (Enable_exponential_dos) {
		site_energies_donor.assign(N_donor_sites, 0);
		site_energies_acceptor.assign(N_acceptor_sites, 0);
		createExponentialDOSVector(site_energies_donor, 0, Energy_urbach_donor, gen);
		createExponentialDOSVector(site_energies_acceptor, 0, Energy_urbach_acceptor, gen);
	}
	else {
		site_energies_donor.push_back(0);
		site_energies_acceptor.push_back(0);
	}
	int donor_count = 0;
	int acceptor_count = 0;
	for (int i = 0; i < lattice.getNumSites(); i++) {
		if (Enable_gaussian_dos || Enable_exponential_dos) {
			if (sites[i].getType() == (short)1) {
				sites[i].setEnergyIt(site_energies_donor.begin() + donor_count);
				donor_count++;
			}
			else if (sites[i].getType() == (short)2) {
				sites[i].setEnergyIt(site_energies_acceptor.begin() + acceptor_count);
				acceptor_count++;
			}
			else {
				cout << getId() << ": Error! Undefined site type detected while assigning site energies." << endl;
				Error_found = true;
			}
		}
		else {
			if (sites[i].getType() == (short)1) {
				sites[i].setEnergyIt(site_energies_donor.begin());
			}
			else if (sites[i].getType() == (short)2) {
				sites[i].setEnergyIt(site_energies_acceptor.begin());
			}
			else {
				cout << getId() << ": Error! Undefined site type detected while assigning site energies." << endl;
				Error_found = true;
			}
		}
	}
	if (Enable_correlated_disorder) {
		createCorrelatedDOS(Disorder_correlation_length);
	}
	//outputVectorToFile(site_energies_donor, "DOS_data.txt");
}

bool OSC_Sim::siteContainsHole(const Coords& coords){
    auto object_ptr = (*lattice.getSiteIt(coords))->getObjectPtr();
    if(object_ptr->getName().compare(Polaron::name)==0){
        return static_cast<Polaron*>(object_ptr)->getCharge();
    }
    return false;
}

void OSC_Sim::updateDynamicsData(){
    static const double step_size = 1.0/(double)Dynamics_pnts_per_decade;
	static int index_prev = -1;
    // Only start dynamics transient calculations if the time elapsed since exciton creation is larger than the transient start time
    if(getTime()>Dynamics_transient_start){
        // If enough time has passed, output next timestep data
        if(getTime()>transient_times[index_prev+1]){
            int index = (int)floor((log10(getTime())-log10(Dynamics_transient_start))/step_size);
            while(index!=0 && index_prev<index-1 && index_prev+1<(int)transient_times.size()){
                transient_excitons[index_prev+1] = N_excitons;
                transient_electrons[index_prev+1] = N_electrons;
                transient_holes[index_prev+1] = N_holes;
                index_prev++;
            }
            if(index<(int)transient_times.size()){
                transient_excitons[index] = N_excitons;
                transient_electrons[index] = N_electrons;
                transient_holes[index] = N_holes;
                index_prev = index;
            }
        }
    }
}

void OSC_Sim::updateToFData() {
	static const double step_size = 1.0 / (double)ToF_pnts_per_decade;
	// Only start ToF transient calculations if enough time has elapsed since the last updated
	if ((getTime() - ToF_creation_time) > transient_times[ToF_index_prev + 1]) {
		list<Polaron> polarons;
		// electrons
		if (!ToF_polaron_type) {
			polarons = electrons;
		}
		// holes
		else {
			polarons = holes;
		}
		int index = (int)floor((log10(getTime() - ToF_creation_time) - log10(ToF_transient_start)) / step_size);
		if (index >= (int)transient_times.size()) {
			return;
		}
		while (index != 0 && ToF_index_prev < index - 1 && ToF_index_prev + 1 < (int)transient_times.size()) {
			for (auto polaron_it = polarons.begin(); polaron_it != polarons.end(); ++polaron_it) {
				int index_tof = distance(ToF_polaron_tags.begin(), find(ToF_polaron_tags.begin(), ToF_polaron_tags.end(), polaron_it->getTag()));
				transient_counts[ToF_index_prev + 1]++;
				// transient_velocities[index_prev+1] += 0;
				transient_energies[ToF_index_prev + 1] += ToF_energies_prev[index_tof];
			}
			ToF_index_prev++;
		}
		for (auto polaron_it = polarons.begin(); polaron_it != polarons.end(); ++polaron_it) {
			// Get polaron site energy and position for previous timestep
			int index_tof = distance(ToF_polaron_tags.begin(), find(ToF_polaron_tags.begin(), ToF_polaron_tags.end(), polaron_it->getTag()));
			transient_counts[index]++;
			double velocity = (1e-7*lattice.getUnitSize()*(polaron_it->getCoords().z - ToF_positions_prev[index_tof])) / (getTime() - ToF_times_prev[index_tof]);
			transient_velocities[index] += velocity;
			// donor
			if (getSiteType(polaron_it->getCoords()) == (short)1) {
				//electron
				if (!ToF_polaron_type) {
					transient_energies[index] += -Lumo_donor + getSiteEnergy(polaron_it->getCoords());
					ToF_energies_prev[index_tof] = -Lumo_donor + getSiteEnergy(polaron_it->getCoords());
				}
				//hole
				else {
					transient_energies[index] += -Homo_donor + getSiteEnergy(polaron_it->getCoords());
					ToF_energies_prev[index_tof] = -Homo_donor + getSiteEnergy(polaron_it->getCoords());
				}
			}
			// acceptor
			else {
				//electron
				if (!ToF_polaron_type) {
					transient_energies[index] += -Lumo_acceptor + getSiteEnergy(polaron_it->getCoords());
					ToF_energies_prev[index_tof] = -Lumo_acceptor + getSiteEnergy(polaron_it->getCoords());
				}
				//hole
				else {
					transient_energies[index] += -Homo_acceptor + getSiteEnergy(polaron_it->getCoords());
					ToF_energies_prev[index_tof] = -Homo_acceptor + getSiteEnergy(polaron_it->getCoords());
				}
			}
			ToF_positions_prev[index_tof] = polaron_it->getCoords().z;
			ToF_times_prev[index_tof] = getTime();
		}
		ToF_index_prev = index;
	}
}
