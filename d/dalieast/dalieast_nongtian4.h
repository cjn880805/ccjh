//nongtian4.h

//Sample for room: �����ũ��4
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ũ��4");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_nongfu2");
	
	add_door("�����������", "�����������", "�����ũ��4");
//	add_door("����Ǵ����", "����Ǵ����", "�����ũ��4");

	set("long", "һƬ�ٺ��ĵ�����������ˮ���﹡�ܸߣ��Ҹ�����Թ��߶�������ھ����൱�����ˮ��������گ��ˮ���㣬�Ӻ��ڶ࣬��Ȼ��ɽ�ص��������Ҳ�������⡣��ȥ������Щ������ӡ�" );

};

RESIDENT_END;
