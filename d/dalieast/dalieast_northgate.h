//northgate.h

//Sample for room: ����Ǳ���
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_northgate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ǳ���");

	set("resident", "����");

	add_npc("pub_playboy");  // add by zdn 2001-07-12

	add_door("����Ƕ�", "����Ƕ�", "����Ǳ���");

	set("long", "������ǣ���������ǣ��Ǵ�����Ķ��ǡ�����گ�ڳ������������ϡ�����͹��������ϡ������˹��������ϡ����������������������Ķ��ϵġ�������������Դ˳�Ϊ�����˴����Ǳ����ţ���÷ϪΪ���ӣ���ǽ����Ϫ�ϣ���ʯ������ݳɣ��߶����壬�����ɣ���������¥��פ�����ڡ���ʯ�ٵ��ӳ���ֱ�����죬����һ��������·����ͨȥ��" );

};


RESIDENT_END;
