# Hospital-Patient-Management-Program
This is a hospital management program that can be used to manage patients, caregivers and appointments.
## User Menu Breakdown
### User input 1
The application asks the user if he wants to create a new instance, if the answer is "Yes", the application asks for a file name and if the file exists the application uses the function "creerInstance" to create a new instance.
### User input 2
The application uses the function "lirePatients" to read the list of saved patients in the created instance.
### User input 3
The application uses the function "lireSoigneurs" to read the list of saved caregivers in the created instance.
### User input 4
The applications prints the list of caregivers, the list of patients and asks the user to chose a patient and a caregiver in the printed lists. Once the applications has the ids of the patient and the caregiver, the applications searchs and prints the corresponding appointment using the caregivers ID.
### User input 5
The application prints the list of caregivers and asks the user to chose a caregiver in the printed list. The application then uses "modifierRendezVous" to modifie the selected appointment.
### User input 6
The applications prints the list of caregivers, the list of patients and asks the user to chose a patient and a caregiver in the printed lists. The application then asks the user to chose an appointment in the list of appointments attached to the patient, proceding to delete it using the function "supprimerRendezVous".
### User input 7
The applications calls the function "ordonnancement" to schedule the created Instance.
### User input 8
The application asks the user of a file name and uses the function "exporterSolution" to export the scheduled Instance.
### User input 9
Quits the application.
