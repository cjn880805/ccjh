//shanlu1.h

//Sample for room: ����Ǵ���ɽ·
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_shanlu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǵ���ɽ·");

	set("resident", "��Ū��");

	add_npc("pub_playboy");
	add_npc("lj_shangtugong");	//�������׶�������
	add_npc("pub_liumang");   // add by zdn 2001-07-13

	add_door("�������Ū��", "�������Ū��", "����Ǵ���ɽ·");
	add_door("����ǽ���ɽ��", "����ǽ���ɽ��", "����Ǵ���ɽ·");

	set("long", "�����ڴ���ɽ���һ����·�ϡ��˼�����������ڣ��������ߣ���ɽ����Խ�ƽ��������ɼ���ѩ��������ظ�ԭȺɽ������һ·��Խɽ��ֱͨ�����ϴ�������ɽ����Щ�����˵Ĵ��䡣");
	
};

RESIDENT_END;
