//yzjw_jiaowai12.h

//Sample for room:  ��������12
//coded by zwb
//data: 2000-11-22

ROOM_BEGIN(CRYZJW_jiaowai12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������12");

	add_npc("animal_dushe");
	add_npc("gaibang_li_sh");

	CBox * box = Add_Box();
	box->add_object("shuzhi", 1);	
	box->set_name( "����");	
	
	add_door("��������11","��������11","��������12");
	add_door("�����ݵ�1","�����ݵ�1","��������12");
 
};


ROOM_END;
