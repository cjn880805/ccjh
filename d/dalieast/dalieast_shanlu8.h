//shanlu8.h

//Sample for room: �����ɽ·8
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ɽ·8");

	set("resident", "������");

	add_npc("pub_daoke");     // 2001-07-12 zdn add

	//the seventh param: to next door id of next room
	add_door("�����ɽ·7", "�����ɽ·7", "�����ɽ·8");
	add_door("�����������", "�����������", "�����ɽ·8");

	set("long", "��·��ɽ�������Ѽ������������ɽ��ͨ����ĵ��ݵش�������ɽ�ƽ�Ϊƽ����ɽ����ż�����̣�͸�����ֵķ�϶������ȥ����Լ�ɼ�һ����ˮ��Щ�����̡�" );
	
};

RESIDENT_END;
