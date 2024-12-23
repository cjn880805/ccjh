//quanzhoucity.h

//Sample for room:  Ȫ��
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
RESIDENT_BEGIN(CRQuanzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��");

	set("resident", "Ȫ��");
	set("capacity", 10);

	add_npc("pub_wangjinhongpu");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	add_npc("helpnpc010");

	if (random(2)==0)
	{
		add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}

				

	add_door("Ȫ�����ŵ���", "Ȫ�����ŵ���", "Ȫ��");
	add_door("Ȫ�ݺ���", "Ȫ�ݺ���", "Ȫ��");

	add_door("Ȫ������", "Ȫ������", "Ȫ��");
	add_door("Ȫ�ݱ���", "Ȫ�ݱ���", "Ȫ��");
//	add_door("Ȫ�ݺ���", "Ȫ�ݺ���", "Ȫ��");
 
};


RESIDENT_END;
