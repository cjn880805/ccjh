//milin.h

//Sample for room: ���������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_milin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	set("resident", "������");

	//add npcs into the room
	add_npc("animal_qingshe");
	
	add_door("�����������", "�����������", "���������");
	add_door("���������ɽ��", "���������ɽ��", "���������");

	set("long", "�˴�ɽ����խ����ľ�ر�ï�ܣ�ɽ��̤������С�����ݺύ�����ľ�ڵ��谭�ţ���·�߲�ͣ���õ�������·������˳��ǰ����������ɽ������������ʱ�������޾��ߣ�ż�����ܿ��������Ŀ�ȸ�ɹ���" );

};


RESIDENT_END;
