//dehuabei.h

//Sample for room: �������گ�»���
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_dehuabei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������گ�»���");

	set("resident", "��گ");

	add_npc("pub_youke");
	add_npc("pub_cunfu");   // add by zdn 2001-07-13

	add_door("�����̫�ͳ�", "�����̫�ͳ�", "�������گ�»���");
	add_door("����ǹٵ�3", "����ǹٵ�3", "�������گ�»���");

	set("long", "��گ���߷��ڴ����챦��䣬ͬ�������ν�ս�����ƾ�ʮ���򡣹��󣬸��߷��л��⣬Ϊһʱ���񣬡����ǰ�ǣ��������񡱡����ǣ�������ʰ�ƾ�������ʿ����������֮���Դ���ɡ���ͬʱ������׫�ģ�����챦ս���Ľ���ͽ������ﲻ���Ѷ����ƵĿ��ԣ������̳ɾޱ������챦ʮһ����������̫�ͳǹ����⡣��");
	
};


RESIDENT_END;
