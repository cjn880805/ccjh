//shanlu7.h

//Sample for room: �����ɽ·7
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ɽ·7");

	set("resident", "������");

	add_npc("pub_jianke");   // 2001-07-12 zdn add

	add_door("�����ũ��3", "�����ũ��3", "�����ɽ·7");
	add_door("�����ɽ·8", "�����ɽ·8", "�����ɽ·7");

	set("long", "�н�����گ��᫵�ɽ���С���ɽ����������ï�ܷ�ʢ����ľ��֦辺���������·�����������ѡ�����ɽ�񾭳����߲ſ��������ĵ�·����������ˣ�������Ȼ��ҪЮ����������ʱ׼������·����ľ������ϰ���" );
	
};

RESIDENT_END;
