//nongtian2.h

//Sample for room: �����ũ��2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ũ��2");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_nongfu");
	add_item("daotian");
//	add_npc("animal_cow");

	add_door("�������٤��", "�������٤��", "�����ũ��2");
	add_door("�����ũ��3", "�����ũ��3", "�����ũ��2");
	add_door("����Ǹ���", "����Ǹ���", "�����ũ��2");

	set("long", "����һС����ͨ��ˮ��أ���گ��ů��ʪ���Թ�����������ֲˮ��Ϊ�����⸽���Ǵ�������ټ���ƽԭ���Σ���Ҫ�Ը���Ϊ���İ����˿�����һЩ��ũ���ػ��ֳ�С�飬һЩ��������������������ˮţ�������е�·����ũ���򶫶�ȥ��" );
	
};


RESIDENT_END;
