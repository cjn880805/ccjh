//laolongtou.h

//Sample for room: ����ͷ
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_laolongtou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ͷ");

	set("resident", "ɽ����");

	//add npcs into the room
	add_npc("pub_fengxifan");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	
	add_door("�����Ӫ", "�����Ӫ", "��������ͷ");
	add_door("����ɽ����", "����ɽ����", "��������ͷ");
	add_door("���������3", "���������3", "��������ͷ");

    set("long","����ͷ�����ﳤ����ˡ��κ�¥Ρ��߾��ͷ��¥�ϡ��۽�����ĺ��ҾӸ����£�ֱ���󺣡��Գκ�¥����һʯ���𼶶�������󺣣�վ��ʯ���ն�¥ƽ̨������������һɫ���ޱ��޼ʣ�������ǧ��" );
	
};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"�����Ӫ") )
	{
		if(!me->query_temp("zhang/����ǿ"))
		{
			return notify_fail("$HIR�ڱ�������ȣ������Ǻ��ˣ���Ӫ�ص���������Ҵ��ĵط�����");
		}
	}
	return CRoom::valid_leave(me, dir);
}

RESIDENT_END;
