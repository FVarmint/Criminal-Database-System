#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>

class Criminal
{
private:

        std::string first_name;
        std::string last_name;
        std::string city;
        std::string age;
        std::string crime_place_name;
        std::string notoriety;

public:

        void IN_insert_in_file();
        void RT_retrieve_from_the_file();
        //forrmation of linked list
        void create_node(std::string first_name, std::string last_name, std::string age, std::string city, std::string crime_place_name, std::string notoriety);
        void LI_list_traversal();

        void search_criminal();
        void delete_node();

        void update_node();



        /// <summary>
        /// Points towards the next node
        /// </summary>
        Criminal* next = NULL;

};

/// <summary>
/// Declaration of a global head variable which will be keeping track of everything for the linked list
/// </summary>
Criminal* head = NULL;



class Login:Criminal{

        ///It will be containg the data for the login Id's
        std::string username;
        std::string password;

        //Login* next=NULL;

public:
        void c_register();
        void c_check(std::string p_username,std::string p_password);
        void c_login();
        void create_login_nodes();

        //Login* next;

};

/// <summary>
/// incomplete
/// </summary>
void Login::c_login()
{
        std::string username;
        std::string password;


        std::cout << "Enter your username" << std::endl;
        std::cin >> username;
        std::cout << "Enter the password" << std::endl;
        std::cin >> password;

        std::transform(username.begin(), username.end(), username.begin(), ::tolower);

        c_check(username, password);
}
void Login::c_register()
{
        std::string m_username;
        std::string m_password;


        std::cout << "Enter a suitable username" << std::endl;
        std::cin >> m_username;
        /// <summary>
        /// Convert string type into lower case letter for a single type input
        /// </summary>
        std::transform(m_username.begin(), m_username.end(),m_username.begin(),::tolower);
        //std::cout << m_username << std::endl;
        ///Successfull conversion.

        std::cout << "Enter the password" << std::endl;
        std::cin >> m_password;
        ///This will be inputted inside the file as it is.
        
        ///Inputting the data into the file

        std::ofstream m_fout;

        /// <summary>
        /// File named Details.txt is opened and writing the obtained data into it.
        /// </summary>
        m_fout.open("Details.txt", std::ios::app);
        m_fout << m_username;
        m_fout << ",";
        m_fout << m_password;
        m_fout << "!\n";

}
void Login::c_check(std::string username,std::string password)
{
        /// <summary>
        /// While checking the login userid and password
        /// </summary>
        /// <param name="username"></param>
        /// <param name="password"></param>
        std::ifstream fin;
        std::string line;

        std::string m_username;
        std::string m_password;
        std::string m_profile_count;

        int options1;

        fin.open("Details.txt",std::ios::in);

        /// <summary>
        /// Loops until the file pointer finds the particular character
        /// </summary>
        while (std::getline(fin, line))
        {
                std::stringstream ss(line);

                getline(ss, m_username, ',');
                getline(ss, m_password, '!');
                
                if (m_username == username)
                {
                        if (m_password == password)
                        {
                                Criminal obj;
                                std::cout << "Login Success" << std::endl;
                                /// <summary>
                                /// Call the administrator function
                                /// </summary>
                                /// <param name="username"></param>
                                /// <param name="password"></param>
                                std::cout << "Please select an option" << std::endl;
                                std::cout << "Press 1 to Delete a Record" << std::endl;
                                //std::cout << "Press 2 to Delete a Record" << std::endl;
                                std::cin >> options1;

                                if (options1 > 1 || options1 <= 0)
                                {
                                        std::cout << "Invalid Option selected" << std::endl;
                                }
                                else
                                {
                                        switch (options1)
                                        {
                                        /*case 1:
                                                obj.RT_retrieve_from_the_file();
                                                obj.update_node();
                                                break;*/

                                        case 1:
                                                obj.RT_retrieve_from_the_file();
                                                obj.delete_node();
                                                break;
                                        }
                                }
                        }
                        else
                                std::cout << "Incorrect Password!!" << std::endl;
                }
                else
                {
                        std::cout << "Incorrect Username!!" << std::endl;
                        break;
                }       
        }
}


/// <summary>
/// Incomplete
/// </summary>


////Update Method UNCOMITTED
//void Criminal::update_node()
//{
//      std::string name;
//      int choice;
//      Criminal* update_pointer=head;
//
//      Criminal* new_pointer;
//
//
//      std::string firstname;
//      std::string lastname;
//      std::string age;
//      std::string notoriety;
//      std::string crimeplace;
//      std::string city;
//
//      std::cout << "Enter the name of the criminal you want to UPDATE Profile of : " << std::endl;
//      std::cin >> name;
//
//      while (update_pointer != NULL)
//      {
//              if (update_pointer->first_name == name)
//              {
//                      std::cout << "Please select what do you want to update" << std::endl;
//                      std::cout << "Press 1 to Update first name" << std::endl;
//                      std::cout << "Press 2 to Update last name" << std::endl;
//                      std::cout << "Press 3 to Update age" << std::endl;
//                      std::cout << "Press 4 to Update Crimeplace" << std::endl;
//                      std::cout << "Press 5 to Update City" << std::endl;
//                      std::cout << "Press 6 to Update Notoriety" << std::endl;
//
//                      std::cin >> choice;
//                      switch (choice)
//                      {
//                              case 1:
//                                      std::cout << "Enter the First name" << std::endl;
//                                      std::cin >> firstname;
//                                      update_pointer->first_name = firstname;
//                                      break;
//                              case 2:
//                                      std::cout << "Enter the Last name" << std::endl;
//                                      std::cin >> lastname;
//                                      update_pointer->last_name = lastname;
//                                      break;
//
//                              case 3:
//                                      std::cout << "Enter the Age name" << std::endl;
//                                      std::cin >> age;
//                                      update_pointer->age = age;
//                                      break;
//                              case 4:
//                                      std::cout << "Enter the Crime-Place" << std::endl;
//                                      std::cin >> crimeplace;
//                                      update_pointer->crime_place_name = crimeplace;
//                                      break;
//                              case 5:
//                                      std::cout << "Enter the city" << std::endl;
//                                      std::cin >> city;
//                                      update_pointer->city = city;
//                                      break;
//                              case 6:
//                                      std::cout << "Enter the Notoriety" << std::endl;
//                                      std::cin >> notoriety;
//                                      update_pointer->notoriety = notoriety;
//                                      break;
//
//                      }
//              }
//      }
//
//
//      std::cout << "Check 1" << std::endl;
//      std::string li_firstname;
//      std::string li_lastname;
//      std::string li_age;
//      std::string li_crimeplace;
//      std::string li_city;
//      std::string li_notoriety;
//
//
//
//      ///insert the key into files
//      new_pointer = head;
//      std::ofstream li_fout;
//
//      li_fout.open("Criminal.txt",std::ios::trunc);
//
//      std::cout << "Check 2" << std::endl;
//
//      while (new_pointer != NULL)
//      {
//              std::cout << "Loop Runs" << std::endl;
//
//              li_firstname = new_pointer->first_name;
//              li_lastname = new_pointer->last_name;
//              li_age = new_pointer->age;
//              li_city = new_pointer->city;
//              li_crimeplace = new_pointer->crime_place_name;
//              li_notoriety = new_pointer->notoriety;
//
//
//
//              li_fout << li_firstname;
//              li_fout << ",";
//              li_fout << li_lastname;
//              li_fout << ",";
//              li_fout << li_age;
//              li_fout << ",";
//              li_fout << city;
//              li_fout << ",";
//              li_fout << crimeplace;
//              li_fout << ",";
//              li_fout << notoriety;
//              li_fout << "!\n";
//
//              new_pointer = new_pointer->next;
//
//      }
//}



/// <summary>
/// Comitted
/// </summary>
void Criminal::delete_node()
{
        /// <summary>
        /// Retrieval Must be Done First
        /// </summary>

        Criminal* m_pointer;
        Criminal* m_previous;


        m_pointer = head;
        m_previous = head;

        int m_count = 0;

        std::string name;

        std::cout << "Enter the name of the criminal you want to Delete ID of : " << std::endl;
        std::cin >> name;

        while (m_pointer != NULL)
        {
                if (m_pointer->first_name == name)
                {
                        if (m_count == 0)
                        {
                                ///Deletion from the beginning
                                m_pointer = m_pointer->next;
                                head = m_pointer;
                                delete(m_previous);
                                std::cout << "Deleted from the Beginning" << std::endl;
                                break;
                        }
                        else if (m_count > 0)
                        {
                                ///Checking if it is in middle
                                if (m_pointer->next != NULL)
                                {
                                        ///it is in middle
                                        m_previous->next = m_pointer->next;
                                        std::cout << "Deleted from the middle" << std::endl;
                                        break;

                                }///Check if it is is end
                                else if (m_pointer->next == NULL)
                                {
                                        m_previous->next = NULL;
                                        std::cout << "Deleted from the end" << std::endl;
                                        break;
                                }
                        }

                }
                else if (m_pointer->next == NULL)
                        std::cout << "The Criminal is not found throughout" << std::endl;

                //Base case will run when the loop does not get effected by the if and else conditions.

                std::cout << "Check 1" << std::endl;

                m_count++;
                m_previous = m_pointer;
                m_pointer = m_pointer->next;

        }

                std::ofstream m_fout;
                m_pointer = head;
                m_fout.open("criminal.txt", std::ios_base::trunc);

                std::string firstname;
                std::string lastname;
                std::string age;
                std::string crimeplace;
                std::string city;
                std::string notoriety;

                std::cout << "Check 2" << std::endl;
                while (m_pointer != NULL)
                {
                        std::cout << "Loop enters" << std::endl;

                        firstname = m_pointer->first_name;
                        lastname = m_pointer->last_name;
                        crimeplace = m_pointer->crime_place_name;
                        city = m_pointer->city;
                        age = m_pointer->age;
                        notoriety = m_pointer->notoriety;


                        m_fout << firstname;
                        m_fout << ",";
                        m_fout << lastname;
                        m_fout << ",";
                        m_fout << age;
                        m_fout << ",";
                        m_fout << city;
                        m_fout << ",";
                        m_fout << crimeplace;
                        m_fout << ",";
                        m_fout << notoriety;
                        m_fout << "!\n";

                        m_pointer = m_pointer->next;

                }
        
}

void Criminal::search_criminal()
{
        Criminal* pointer;
        pointer = head;
        std::string name;

        std::cout << "Enter the name of the criminal you want to find :" << std::endl;
        std::cin >> name;

        while (pointer != NULL)
        {
                
                if (pointer->first_name == name)
                {
                        std::cout << "Found" << std::endl;

                        /// <summary>
                        /// Show profile of the criminal
                        /// </summary>
                        break;
                }
                else if (pointer->next == NULL)
                {
                        std::cout << "Criminal Not Found" << std::endl;
                }
                pointer = pointer->next;

        }
}

void Criminal::LI_list_traversal()
{
        Criminal* LI_m_temp;
        LI_m_temp = head;
        int count = 1;

        while (LI_m_temp!= NULL)
        {
                        std::cout << "\t     -------------";
                        std::cout << "\n\t    |"; std::cout << "  Profile " << count; std::cout << "  |";
                        std::cout << "\n\t     -------------";
                        std::cout << "\n\tThe First name of the criminal is : " << LI_m_temp->first_name << std::endl;
                        std::cout << "\n\tThe Last name of the criminal is : " << LI_m_temp->last_name << std::endl;
                        std::cout << "\n\tThe city of the criminal is : " << LI_m_temp->city << std::endl;
                        std::cout << "\n\tThe name of the Crime Place is : " << LI_m_temp->crime_place_name << std::endl;
                        std::cout << "\n\tThe age of the Criminal is : " << LI_m_temp->age << std::endl;
                        std::cout << "\n\tThe Notoriety of the Criminal is : " << LI_m_temp->notoriety << std::endl;


                        std::cout << "     -----------------------------------" << std::endl;
                        
                        LI_m_temp = LI_m_temp->next;
                        count++;
        }
}


void Criminal::create_node(std::string p_first_name,std::string p_last_name,
        std::string p_age, std::string p_city, std::string p_crime_place_name, std::string p_notoriety)
{
        Criminal* temp;
        Criminal* linker;
        
        linker = head;
        temp = new Criminal();
        
        temp->first_name = p_first_name;
        temp->last_name = p_last_name;
        temp->age = p_age;
        temp->city = p_city;
        temp->crime_place_name = p_crime_place_name;
        temp->notoriety = p_notoriety;
        temp->next = NULL;

        //temp->notoriety = p_notoriety;

        if (head == NULL)
        {
                head = temp;
                ///updated
                head->next = NULL;
        }
        else
        {
                linker = head;
                head = temp;
                head->next = linker;
                
        }
}


void Criminal::RT_retrieve_from_the_file()
{
        //Read from file
        //it is an object
        std::ifstream fin;
        
        std::string RT_m_first_name;
        std::string RT_m_last_name;
        std::string RT_m_age;
        std::string RT_m_city;
        std::string RT_m_crime_place_name;
        std::string RT_m_notoriety;

        
        std::string line;

        /// <summary>
        /// opens the file
        /// </summary>
        fin.open("criminal.txt");

        /// <summary>
        /// Inserts the file into a loop and starts reading the file line by line
        /// </summary>
        while (std::getline(fin, line))
        {
                /// <summary>
                /// Breaks the line into stream...like cin.
                /// </summary>
                std::stringstream ss(line);

                getline(ss, RT_m_first_name, ',');
                getline(ss, RT_m_last_name, ',');
                getline(ss, RT_m_age, ',');
                getline(ss, RT_m_city, ',');
                getline(ss, RT_m_crime_place_name, ',');
                getline(ss, RT_m_notoriety, '!');

                //std::cout << RT_m_name << RT_m_age << RT_m_city << RT_m_crime_place_name << RT_m_notoriety;
                
                /// <summary>
                /// creates memory block
                /// Class load;
                /// </summary>
                
                create_node(RT_m_first_name,RT_m_last_name,RT_m_age,RT_m_city,RT_m_crime_place_name,RT_m_notoriety);///function call
        }

}



/// <summary>
/// Only this will be containing the integer part rest all will be containing the string part.
/// This fucntion interacts with the file and the data part.
/// This function is introduced inside the class only for the puspose of encapsualtion and rest assured has nothing to do 
/// with the actual implementation
/// 
/// It does not take any paramter.
/// It writes the content inside the file name Criminal.txt
/// 
/// </summary>
void Criminal::IN_insert_in_file()
{
        /// <summary>
        /// Declaration of the object which is responsible for writing inside the file.
        /// </summary>
        std::ofstream fout;
        
        
        /// <summary>
        /// Declaration of local variables to temporarily store the values before writing inside the file.
        /// </summary>
        std::string IN_m_first_name;
        transform(IN_m_first_name.begin(), IN_m_first_name.end(), IN_m_first_name.begin(), ::tolower);

        std::string IN_m_last_name;
        transform(IN_m_last_name.begin(), IN_m_last_name.end(), IN_m_last_name.begin(), ::tolower);

        int IN_m_age;

        std::string IN_m_city;
        transform(IN_m_city.begin(), IN_m_city.end(), IN_m_city.begin(), ::tolower);

        std::string IN_m_crime_place_name;
        transform(IN_m_crime_place_name.begin(), IN_m_crime_place_name.end(), IN_m_crime_place_name.begin(), ::tolower);

        int IN_m_notoriety;


        fout.open("criminal.txt",std::ios_base::app);

        if (!fout.is_open())
        {
                std::cout << "The file might be bad please replace the file or check again" << std::endl;
        }
        else
        {

                std::cout << "Enter the First name of the criminal" << std::endl;
                std::cin >> IN_m_first_name;
                std::cout << "Enter the Last name of the criminal" << std::endl;
                std::cin >> IN_m_last_name;
                std::cout << "Enter the age of the criminal" << std::endl;
                std::cin >> IN_m_age;
                std::cout << "Enter the name of the city where the crime has happened ? " << std::endl;
                std::cin >> IN_m_city;
                std::cout << "Enter the name of the place where the crime happened ? " << std::endl;
                std::cin >> IN_m_crime_place_name;
                std::cout << "Enter the Level of notoriety of the criminal" << std::endl;
                std::cin >> IN_m_notoriety;

                

                fout << IN_m_first_name;
                fout << ",";
                fout << IN_m_last_name;
                fout << ",";
                fout << IN_m_age;
                fout << ",";
                fout << IN_m_city;
                fout << ",";
                fout << IN_m_crime_place_name;
                fout << ",";
                fout << IN_m_notoriety;
                fout << "!\n";
        }
}


void Display_data(Criminal object)
{
        int option;
        

        std::cout << "\n\t 1. Press 1 to Enter the data. " << std::endl;
        std::cout << "\n\t 2. Press 2 to see the Profiles " << std::endl;
        std::cout << "\n\t 3.Press 3 to search for the Criminal inside the database" << std::endl;
        std::cin >> option;

        if (option > 3 || option <= 0)
        {
                std::cout << "Invalid Option Chosen" << std::endl;
                std::cout << "Please select again" << std::endl;
                Display_data(object);
        }
        else
        {
                switch (option)
                {
                case 1: ///Enter the data will Run.
                        object.IN_insert_in_file();
                        //Display_data(object);
                        break;

                case 2: ///Displays the linked list in the form of Profiles
                        object.RT_retrieve_from_the_file();
                        object.LI_list_traversal();
                        //Display_data(object);
                        break;
                
                case 3:
                        object.RT_retrieve_from_the_file();
                        object.search_criminal();
                        //Display_data(object);
                        break;
                }
        }
}

void Display_admin(Login object)
{
        int options;
        std::cout << "\n\t 1. Press 1 to Login. " << std::endl;
        std::cout << "\n\t 2. Press 2 to Register " << std::endl;
        std::cin >> options;

        if (options > 2 || options <= 0)
        {
                std::cout << "Invalid Options Selected" << std::endl;
                Display_admin(object);
        }
        else
        {
                switch (options)
                {
                case 1:
                        object.c_login();
                        break;
                
                case 2: 
                        object.c_register();
                        break;
                }
        }

}

int main()
{
        /// <summary>
        /// Declaration of the objects
        /// </summary>
        /// <returns></returns>
        Criminal obj;
        Login obj1;

        /// <summary>
        /// Declaration of the fucntions
        /// </summary>
        /// <returns></returns>
        void Display_data(Criminal obj);
        void Display_admin(Login obj1);
        int options2;

        std::cout << "\n\t\t\t\t  ---------------------------------------------";
        std::cout << "\n\t\t\t          |"; std::cout << "  welcome to the Criminal Database system : "; std::cout << "|";
        std::cout << "\n\t\t\t\t  ---------------------------------------------";

        std::cout << "\n\n\t\t\tRead me : " << std::endl;
        std::cout << "\n\t1. This is a criminal database system" << std::endl;
        std::cout << "\n\t2. This keeps records of the criminals" << std::endl;
        std::cout << "\n\t3. This program uses linker profile to attach the gang related profiles " << std::endl;
        std::cout << "\n\t4. This program accessess the file name criminal.txt to access " << std::endl;
        std::cout << "\n\t5. The later phase of the program will let the user to search for any criminal using name, age, sex and many more " << std::endl;

        std::cout << "\t     -------------------------------------------------------------------";
        std::cout << "\n\t\tPlease select the appropriate options for registering the data" << std::endl;
        std::cout << "\t     -------------------------------------------------------------------";

        std::cout << "\n\t 1. Press 1 to Select Admin priviledges. " << std::endl;
        std::cout << "\n\t 2. Press 2 to Register Criminal " << std::endl;
        std::cin >> options2;

        switch (options2)
        {
        case 1:
                Display_admin(obj1);
                break;

        case 2:Display_data(obj);
                break;
        }


}
