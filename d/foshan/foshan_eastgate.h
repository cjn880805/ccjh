//eastgate.h
//Sample for room: ��ɽ����
//coded by zwb
//data: 2000-11-23

RESIDENT_BEGIN(CRFoShan_eastgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ����");
	set("resident", "��ɽ");

	add_npc("pub_bing");  //add by zdn 2001-07-13
	add_door("��ɽ", "��ɽ", "��ɽ����");
	add_door("��ɽ�ּ��8", "��ɽ�ּ��8", "��ɽ����");

	set("long", "�����Ƿ�ɽ��Ķ��š��������߾�Ҫ�뿪��ɽ��ȥ�������ˡ�����һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���" );

};

RESIDENT_END;
