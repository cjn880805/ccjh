//nongtian3.h

//Sample for room: �����ũ��3
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ũ��3");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_nongfu2");
	
	add_door("�����ũ��2", "�����ũ��2", "�����ũ��3");
	add_door("�����ɽ·7", "�����ɽ·7", "�����ũ��3");

	set("long", "�����Ѿ���ƽԭ�ľ�ͷ����������վ���ɽ���ˣ�һЩ��ũ�����٤������ķ������ǵطֲ���ɽ���£�һЩ�����������������������·���ϵ�ɽ�����Ѷ�ȥ��" );
	
};

RESIDENT_END;
