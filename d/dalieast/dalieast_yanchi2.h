//yanchi2.h

//Sample for room: ������سص̰�2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanchi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������سص̰�2");

	set("resident", "��٤��");

	add_npc("pub_cunfu");
	add_npc("pub_bing");         //add by zdn 2001-07-12

	add_door("������سص̰�1", "������سص̰�1", "������سص̰�2");
	add_door("������سص̰�3", "������سص̰�3", "������سص̰�2");

	set("long", "��ط羰���ˣ��ص̰�����������к��У����ϱ��Ա�ˮ������̲����ݺ�֮�࣬�����ڵ�أ����ֻ����£���������ɽ֮�������к��У�ң������ɽɫ����ӳ�ز��䣬������ˮ��������̣���Ȼ��ʤ��" );
	
};



RESIDENT_END;
