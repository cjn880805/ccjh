//cangshanzhong.h

//Sample for room: ��ɽ�в�
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_cangshanzhong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ�в�");

	set("resident", "�¹س�");

	add_npc("pub_liumang");
	add_npc("pub_liumang");       //add by zdn 2001-07-13

	add_door("������¹س�", "������¹س�", "����ǲ�ɽ�в�");
	add_door("����ǽ�����", "����ǽ�����", "����ǲ�ɽ�в�");
	add_door("����ǲ�ɽɽ·", "����ǲ�ɽɽ·", "����ǲ�ɽ�в�");

	set("long", "�������ڲ�ɽ�в�ɽ�ߣ��˼���μ��գ�����ɽ�����ƣ��м�һ����᫲�ƽ��ɽ·��·����Զһ������Ա���ƫ��������������¡¡ˮ��ңң���ţ�������گ����--��ˮ����·�������������������ıؾ�֮;��ʱ�п��̹������ɴ����ϴ�Խ��ɽ�ɵ��¹سǣ����治Զ���ǳ���ɽ��ɽ�ڡ�" );
	
};


RESIDENT_END;
