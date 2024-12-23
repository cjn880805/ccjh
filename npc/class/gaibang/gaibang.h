//gaibang.h
//����
//Lanwood 2000-01-06

#define NPCGAIBANG_BEGIN(npc_name) class npc_name : public CNgaibang	{	public:	npc_name(){};	virtual ~npc_name(){};
#define NPCGAIBANG_END		};	

NPC_BEGIN(CNgaibang);

int accept_object(CChar * me, CContainer * obj)
{
        if (DIFFERSTR(me->querystr("family/family_name"), "ؤ��"))
		{
			say("���������������", me);
			SendMenu(me);
			return 0;
		}

        if ( me->query_temp("have_cloth") && me->present("po bu") )
        {
            say("�㲻���Ѿ����Ʋ�ô?", me);
			SendMenu(me);
            return 0;
        }

        if (
				( me->query("beggarlvl") == 0 && me->query_combat_exp() <= 500) 
			||  ( me->query("beggarlvl") == 1 && me->query_combat_exp() <= 1000)
			||  ( me->query("beggarlvl") == 2 && me->query_combat_exp() <= 3000)
			||	( me->query("beggarlvl") == 3 && me->query_combat_exp() <= 5000)
			||  ( me->query("beggarlvl") == 4 && me->query_combat_exp() <= 10000)
			||  ( me->query("beggarlvl") == 5 && me->query_combat_exp() <= 15000)
			||  ( me->query("beggarlvl") == 6 && me->query_combat_exp() <= 20000)
			||  ( me->query("beggarlvl") >= 7 && me->query_combat_exp() <= 30000))
        {
             say("�����ǵ�ŧˮ���ҿ������˰ɡ�", me);
			 SendMenu(me);
             return 1;
        }

        if ( 
				(me->query("beggarlvl") == 0 && EQUALSTR(querystr("title"), "ؤ��һ������"))
			||  (me->query("beggarlvl") == 1 && EQUALSTR(querystr("title"), "ؤ���������") )
			||  (me->query("beggarlvl") == 2 && EQUALSTR(querystr("title"), "ؤ����������"))
			||  (me->query("beggarlvl") == 3 && EQUALSTR(querystr("title"), "ؤ���Ĵ�����"))
			||  (me->query("beggarlvl") == 4 && EQUALSTR(querystr("title"), "ؤ���������") )
			||  (me->query("beggarlvl") == 5 && EQUALSTR(querystr("title"), "ؤ����������"))
			||  (me->query("beggarlvl") == 6 && EQUALSTR(querystr("title"), "ؤ���ߴ�����"))
			||  (me->query("beggarlvl") == 7 && EQUALSTR(querystr("title"), "ؤ��˴�����"))
			||  (me->query("beggarlvl") == 8 && EQUALSTR(querystr("title"), "ؤ��Ŵ�����")))
        {
			if( EQUALSTR(obj->querystr("base_name"), "qingzhu_ling")
				&& ! me->query_temp("have_cloth"))
          {
				destruct(obj);

				me->set_temp("fight_ok", 1);
				say("�ã���Ȼ����������ǾͿ���������ˡ�", me);
				AddMenuItem("��ʼ����", "$0bishi $1", me);
				AddMenuItem("��������", "", me);
				
				SendMenu(me);
				return 1;
          }
       }

       say(g_Channel.do_emote(this, 0, "smile", 1), me);
       say("������Ȼֻ������������Ҳ�ǲ��еġ�", me);
       say("�ⶫ�����㻹���Լ����Űɡ�", me);
	   SendMenu(me);
       return 0;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "bishi") == 0 && me->query_temp("fight_ok"))
	{
		Do_BiShi(this, me, "�������Ի�");
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//���Խ���
void is_defeated(CChar * winner, CChar * failer)
{
	if(failer == this)
	{
		if(! winner->query_temp("fight_ok")) return;

		say("��ү��������ã�����������������Ʋ��Ҽ���ȥ !");
		winner->set("newtitle", this->querystr("title"));
        winner->set_temp("have_cloth", 1);
        load_item("po_bu")->move(winner);
		return;
	}
	
	say("��������Ҳ�������Լҳ��˼���ë !");
	return;	
}

void accept_student(CChar * who)
{
	char msg[80];

	if(EQUALSTR(who->querystr("family/family_name"), "ؤ��") && 
		this->query("beggarlvl") > (who->query("beggarlvl") + 2))
	{
		say ("ؤ��ų����µ�һ�����ɭ�ϲ���Խ����ʦ�ģ���һ�������ϵĲ������������������Ұɡ�");
		return;
	}
	if(EQUALSTR(who->querystr("family/family_name"), "ؤ��") && 
		who->query("beggarlvl") >= this->query("beggarlvl"))//��Ҵ�������NPC
	{
		say ("ǰ����Ҫ��С�Ŀ���Ц���ҿɵ������𰡡�");
		return;
	}
	else
	{
		say ("�ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
		command(snprintf(msg, 80, "recruit %ld", who->object_id()));
		who->set("class", "beggar");
	}
	return;
}

NPC_END;
