//ershuiqiao.h

//Sample for room: ����Ƕ�ˮ��
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_ershuiqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ƕ�ˮ��");

	set("resident", "�¹س�");

	add_npc("pub_girl1");
	add_npc("pub_boy");    // add by zdn 2001-07-13

	add_door("����Ǳ���", "����Ǳ���", "����Ƕ�ˮ��");
	add_door("������¹س�", "������¹س�", "����Ƕ�ˮ��");

	set("long", "һ�������ಽ����ʯ�š����ź���ˮ�������¹سǺʹ���ǣ������峺�Ķ�ˮ������ȥ���ű������¹سǵĳ��ţ�����һ·����ʮ���Ｔ�ɵ�����ǡ�");
	
};

RESIDENT_END;
