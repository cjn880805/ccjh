//yzjw_jiaowai11.h

//Sample for room:  ��������11
//coded by zwb
//data: 2000-11-22
ROOM_BEGIN(CRYZJW_jiaowai11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������11");

	add_npc("animal_dushe");
	add_npc("gaibang_yu_hx");
	
	CBox * box = Add_Box();
	box->add_object("shitou", 1);	
	box->set_name( "����");		

	add_door("��������10","��������10","��������11");
	add_door("��������12","��������12","��������11");
 
};


ROOM_END;
