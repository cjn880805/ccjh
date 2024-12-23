//guangchang.h

//Sample for room: �ʹ��㳡


ROOM_BEGIN(CRLingZhou_guangchang);

virtual void create()		
{
	set_name( "�ʹ��㳡");
	add_door("���ݻʹ����3", "���ݻʹ����3", "���ݻʹ��㳡");
	add_door("���ݻʹ�����", "���ݻʹ�����", "���ݻʹ��㳡");

	add_npc("lingzhou_gongweishi");
	add_npc("lingzhou_gongweishi"); 

	set("no_fight",1);
	set("no_cast",1);

	set("long", "����������Ļʹ��㳡�����ȿ����������ţ��������ȭͷ���ͭ�����ŵ�����վ�������¼���������ʿ���䱸���ϡ�");  
};


int valid_leave(CChar * me, const char * dir)
{
	CNpc * ljnpc;
	if(EQUALSTR(dir,"���ݻʹ�����"))
	{
		if(!me->query("lj/renwu11"))
		{
			message_vision("$HIR�ʹ���ʿ������ס���㣬���󵨿�ͽ���ʹ�Ҳ��������Ҵ��ĵط�����", me);
			return 0;
		}
		else if(EQUALSTR(me->querystr("gender"), "Ů��") )
		{
			if(DIFFERSTR(me->querystr_temp("apply/name"),"����"))
			{
				message_vision("$HIR�ʹ���ʿ������ס���㣬���������Ů�ˣ��α����μӱ��������أ�����", me);
				return 0;
			}
			else if(!me->query_temp("lj/renwu111"))
			{
				message_vision("$HIR�ʹ���ʿ������ס���㣬��������������δ���е�ǳ���ˡ�����", me);
				return 0;
			}
			else
			{
				static char lj_npc[15][20]={"lj_chengjialu","lj_zhoubotong","lj_zhangsanfeng","lj_wanerlaqi",
					"lj_nanmonong","lj_linhugongzi","lj_hufei","lj_gouzhazhong","lj_duaer","lj_diyun","lj_beixiaofeng",
					"lj_linmuming","lj_ludinggong","lj_miaorenhuang","lj_yuanchenzhi"};
				if(!me->query_temp("lj/renwu112"))
				{
					for(int i=0;i<15;i++)
					{
						ljnpc = load_npc(lj_npc[i]);
						ljnpc->move(load_room("���ݻʹ�����"));
					}
					me->set_temp("lj/renwu112",1);
				}
				return CRoom::valid_leave(me, dir);
			}
		}
		else
		{
			message_vision("$HIR�һ裡�����еģ���ô���ܽӵ���������أ�����ǧѽ��", me);
			return 0;
		}
	}
	return CRoom::valid_leave(me, dir);
}

ROOM_END;
