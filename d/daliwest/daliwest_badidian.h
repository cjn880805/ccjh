//badidian.h

//Sample for room: �͵ĵ�
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiWest_badidian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�͵ĵ�");

	set("resident", "����");
	
	add_npc("pub_shaonu");  //add by zdn 2001-07-13

	add_door("���������", "���������", "����ǰ͵ĵ�");
	add_door("�������ˮ�ذ�", "�������ˮ�ذ�", "����ǰ͵ĵ�");
	add_door("����Ƕ���ˮ�ӹ�", "����Ƕ���ˮ�ӹ�", "����ǰ͵ĵ�");

	set("long", "������Ǵ�������Ҫ��͵ĵ飬�����ĵ���Ҫ�θ���������Ĳ���ֲ��ڸ��������ڶ���ˮ�ȵ����У��͵ĵ����ܶ�ũ��Դ�Ϊ���ģ���·��ͨ�˴����Ӹ����Ĳ��䡣" );
	
};


RESIDENT_END;
