//dalinorth.h

//Sample for room: ����Ǳ�
//coded by zouwenbin
//data: 2000-11-15

RESIDENT_BEGIN(CRDaLiNorth_dalinorth);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǳ�");

	set("resident", "����");

	add_npc("pub_shiwei2");
	add_npc("pub_shiwei2");        //add by zdn 2001-07-13

	add_door("̫�ͳ�", "�����̫�ͳ�", "����Ǳ�");
	add_door("��ˮ��", "����Ƕ�ˮ��", "����Ǳ�");
	add_door("��ˮ��", "����Ƕ�ˮ��", "����Ǳ�");

	set("long", "�����Ǹ���·�ڡ��ϱ߾��Ǵ���ǵı����ˣ���·������ֲ���ȥ�ɵ�̫�ͳǣ�����ͨ���¹سǣ�Ҳͨ��ɽ����ȥ�β�ɽ�ͳ�ʥ�µıؾ�֮·��" );

};


RESIDENT_END;
