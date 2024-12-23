//sichouzilu1.h

//Sample for room: ˿��֮·1
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_sichouzilu1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˿��֮·1");
				
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
		add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	add_door("�����ԭ", "�����ԭ", "����˿��֮·1");
	add_door("�����Į", "�����Į", "����˿��֮·1");
	add_door("������ɽ����", "������ɽ����", "����˿��֮·1");
	add_door("����˿��֮·2", "����˿��֮·2", "����˿��֮·1");
	
};


XIYU_END;
