//bijishan.h

//Sample for room: ����Ǳ̼�ɽ��
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_bijishan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǳ̼�ɽ��");

	set("resident", "�̼�ɽ");

	//add npcs into the room
	add_npc("pub_youke");
	add_npc("dali_wuliangdizi");      //add by zdn 2001-07-20
	
	add_door("�������Ϫ��̶", "�������Ϫ��̶", "����Ǳ̼�ɽ��");
	add_door("������س�С·2", "������س�С·2", "����Ǳ̼�ɽ��");

	set("long", "�̼�ɽ���ڵ�ص������ϣ����ض��Ǹ�ˮ������ɽ�Ƹ������ƣ�ɽ�����繫������ɽ��ľ�Դ����Ρ��˴����Ǽ������Ѵ��ƶˣ��������һƬ��������ʤ�ա�ɽ��������������ݡ�����������ɽ֮·��" );

};

RESIDENT_END;
