//tianweijing.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_tianweijing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	set("resident", "ϲ��");

	add_npc("pub_playboy");
	add_npc("pub_youke");   //add by zdn 2001-07-13

	add_door("����Ǵ�·4", "����Ǵ�·4", "�����������");
	add_door("�����ϲ�ݳ�", "�����ϲ�ݳ�", "�����������");

	set("long", "�˴���˵������ʱ�����������ߴ����ϻ�֮�����ϻ�Ի������������Ҳ����Ƚ������˲�����Ҳ�������ʴ˵���������һ����ͨ�ϱ��Ĵ�·����ȥʮ����ϲ�ݳǣ�����Լ��ʮ��ɴ����ǡ�" );
};

RESIDENT_END;
