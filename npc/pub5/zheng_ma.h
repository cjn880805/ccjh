//zheng__ma.c ����

NPC_BEGIN(CNzheng_ma);

virtual void create()
{
	set_name("����", "ma yu");
	set("gender", "����");
	set("age", 42);
	set("class", "taoist");
	set("nickname","������");
	set("long","�������������Ĵ���ӣ�ȫ������֮�ף����������������ˡ�����ü��Ŀ���Ͱ����ף���Ц�ſ����㡣");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 28);
	set("foolid",54);
	set("int", 32);
	set("con", 31);
	set("dex", 30);
	set("icon",taoist);
	set_weight(50000000);
	
	set("title","ȫ������֮��");
	
	set("chat_chance_combat", 60);
	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 100);
	
	set("combat_exp", 500000);
	set("score", 300000);
	
	set_skill("force", 220);
	set_skill("sword", 220);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("unarmed",220);
	set_skill("strike",180);

	set_skill("xiantian_qigong", 220);    //��������
	set_skill("quanzhen_jian",220);  //ȫ�潣
	set_skill("jinyan_gong", 200);   //���㹦
	set_skill("haotian_zhang", 220);    //�����

	set_skill("literate",160);
	set_skill("taoism",150);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("ȫ���", 2, "����");
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set("chat_chance_combat", 20);  

	set_inquiry("�������",ask_tiangang);
}

//����
void die()
{
	CFightRoom * obj=(CFightRoom *)environment();
	obj->add("zheng/zhengzu",1);
	if(obj->query("zheng/zhengzu")<=6)
	{
		revive(1);
		message_vision("\n$YELֻ��ȫ������ÿ�˵ݳ�һ�ƣ���һ��ȴ��������֮�˼��ϣ�Ϊ�׵�$N��ʱ�������˫����ǰƽ�ѣ�һ����𣺿���", this);
		set("max_hp",30000);
		set("eff_hp",30000);
		set("hp",30000);
	}
	else
	{
		message_vision("\n$N��Ц������ϲ���������������", this);
		DTItemList * list = obj->Get_ItemList();  
//		char msg[255];
		POSITION p = list->GetHeadPosition(); 
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			CChar * target = (CChar *)obj;  
			if(is_fighting(target)==0 && !userp(target) && !EQUALSTR(target->querystr("nickname"), "������"))
			{
//				message_vision(snprintf(msg, 255, "$HIR%s��ʲô%d��",target->name(1),is_fighting(target)), this);
				destruct(target);
				continue;
			}
		}
		obj->End_Fight();
	}
}

//ս����
void attack(CChar *me)
{
	CFightRoom * obj=(CFightRoom *)environment();
	int idx;
	CChar * robber;
	static char qiangdao[6][20]={"zheng_hao","zheng_liu","zheng_qiu","zheng_sun","zheng_tan","zheng_wangchuyi"};

	if(obj->query("zheng/count")<3)
	{
		for(idx=random(6)+1;idx<6;idx++)
		{
			robber = load_npc(qiangdao[idx-1]);
			if(idx!=obj->query("zheng/friend1_idx")&& idx!=obj->query("zheng/friend2_idx")&&idx!=obj->query("zheng/friend3_idx"))
			{
				if(obj->query("zheng/friend1_idx")==0)
				{
					obj->set("zheng/friend1_idx",idx);
					obj->set("zheng/friend1_name",robber->name(1));
				}
				else if(obj->query("zheng/friend2_idx")==0)
				{
					obj->set("zheng/friend2_idx",idx);
					obj->set("zheng/friend2_name",robber->name(1));
				}
				else
				{
					obj->set("zheng/friend3_idx",idx);
					obj->set("zheng/friend3_name",robber->name(1));
				}
				robber->move(obj);
				obj->Join_Team(robber,CFightRoom::FIGHT_TEAM_A);
				obj->add("zheng/count",1);
				message_vision("\n$HIW����һ�����ȣ�ʦ���ǣ������ͣ�", this);
				message_vision("���Ͷ�ʱһ�䣡\n", this);
				switch(random(9))
				{
				case 0:
					message_vision("$HIR��ֻ������һ�䣬���岻�ɵĿ����������λ������һ��������������ŵ�����Ҷ��ֱ���������",this);
					if(random(2))
						message_vision("$YEL�㲻�Ų�æ������ȫ�ĵط���",this);
					else
						message_vision("$HIR�����������ܣ��Ѿ����ݶ�ҶƬ���ˡ�",this);
					break;
				case 1:
					message_vision("$HIR����һ�䣬�������������λ�����Զ������һ�����ǣ�ֱ���������",this);
					if(random(2))
						message_vision("$YELֻ������������һ����������һ�����춯�صľ޺�, ���Ǹ�����ķ����ˡ�",this);
					else
						message_vision("$HIRɲ�Ǽ䣬������һ�ű���������ţ�������������ϡ�",this);
					break;
				case 2:
					message_vision("$HIR�����ǰһ������Ȩ��λת�������ǰ�����д����������죬����һ�˽�һ�ˣ�ֱ����ӿ����",this);
					if(random(2))
						message_vision("$YEL�������񹦣������α�ȫ�����ױܿ������ˡ�",this);
					else
						message_vision("$HIRֻ���㱻���˴�����ֲ�����������Ѫ��",this);
					break;
				case 3:
					message_vision("$HIR��ֱ�ӳ������λ��ȥ��������ǰ�������ɲʱ�䣬ɶҲ�������ˡ�",this);
					if(random(2))
						message_vision("$YEL��˫�ֽ���̫��Ѩ�����ڿ�������Χ���龰��",this);
					else
						message_vision("$HIRֻ�������һ�У�˫����������Ѫ��",this);
					break;
				case 4:
					message_vision("$HIRͻȻ�����������һת��ֱ���������Ȩ��λ��һ˲�䣬��������ֱ���������",this);
					if(random(2))
						message_vision("$YELֻ����һ���������ֱ�������ȥ�����������顣",this);
					else
						message_vision("$HIR������޷����������������⡣",this);
					break;
				case 5:
					message_vision("$HIR������˿�����λ������ð���˰˸�ʯ�񣬰�������Χס��",this);
					if(random(2))
						message_vision("$YELֻ���㹥��󷽵�ʯ��˲��˸�ʯ����ʧ����Ӱ�٣�ԭ���ǻþ���",this);
					else
						message_vision("$HIR�����󷽵�ʯ�������������ǣ������ͷ�����ǣ������ڵء�",this);
					break;
				case 6:
					message_vision("$HIR������һ�����ƽ���������λ�����ϵ��Ӳ�ͻȻ�䳤��֣������ذ����ס��",this);
					if(random(2))
						message_vision("$YEL��ʹ����һ�н���ѿǣ��������ӲݵĲ��ơ�",this);
					else
						message_vision("$HIR�㲻�����ѱ��Ӳݲ��ô�����������Ԫ�����ˡ�",this);
					break;
				case 7:
					message_vision("$HIR�������������λ��������������������ɹ�����",this);
					if(random(2))
						message_vision("$YEL�㲻�Ų�æ�������񹦣�ֻ���������γ�һ���ܴ�ķ����֣�������������Ӱ�졣",this);
					else
						message_vision("$HIR�����Ա�һԾ��ͼ���������֪�Ա�Ҳ�л����㱻����ײ�����š�",this);
					break;
				case 8:
					message_vision("$HIR��Ȼ��ǰģ�����壬ԭ��������������λ����ض�������ء�",this);
					if(random(2))
						message_vision("$YELֻ������ӯ�����˼��£�����������ص��˰�ȫ�ط���",this);
					else
						message_vision("$HIR��һ��С��̤�����󣬺ܿ��������ȥ����׽ס�Աߵ���֧�ò����ײ�����������ء�",this);
					break;
				}
				break;
			}
		}
	}
}

static char * ask_tiangang(CNpc *me,CChar *who)
{
	CContainer * env = (CChar *)me->environment();
	CChar * robber;
	CFightRoom * obj;

	message_vision("$HIRʦ���ǣ������������", me,who);

	obj = (CFightRoom *)env->present("fight_room_tiangang");
	if(! obj)
	{
		obj = (CFightRoom *)load_item("fight_room");		
	
		obj->set("room_locked", FIGHT_NO_JOIN);
		obj->set_name( "�������", "fight_room_tiangang");
		obj->set("zheng/count",3);
		obj->move(env);

		static char qiangdao[6][20]={"zheng_hao","zheng_liu","zheng_qiu","zheng_sun","zheng_tan","zheng_wangchuyi"};
		me->move(obj);
		obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);
		for(int i=0;i<3;i++)
		{
			robber = load_npc(qiangdao[i]);
			robber->move(obj);
			switch(i)
			{
			case 0:
				obj->set("zheng/friend1_idx",i+1);
				obj->set("zheng/friend1_name",robber->name(1));
				break;
			case 1:
				obj->set("zheng/friend2_idx",i+1);
				obj->set("zheng/friend2_name",robber->name(1));
				break;
			case 2:
				obj->set("zheng/friend3_idx",i+1);
				obj->set("zheng/friend3_name",robber->name(1));
				break;
			}
			obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);	
		}
	}
	if(who) 
	{
		who->move(obj);
		obj->Join_Team(who, CFightRoom::FIGHT_TEAM_B);
		obj->Begin_Fight(0);
	}
	else
		return "";
	return "";
}

//ս���е���Ϣ
virtual char * chat_msg_combat()
{
	char msg[255];
	CFightRoom * obj=(CFightRoom *)environment();
	CChar * me = NULL;
	CChar * who = NULL;
	CChar * robber;
	int idx;
	static char qiangdao[6][20]={"zheng_hao","zheng_liu","zheng_qiu","zheng_sun","zheng_tan","zheng_wangchuyi"};

	if(environment()->Query(IS_FIGHTROOM))
	{
		me = obj->Select_Member(1 - query_team());
		who = obj->Select_Member(query_team());
	}

	if(! me) return 0;
	if(! who) return 0;
	switch(random(4))
	{
	case 0:
	case 1:
	case 2:
		message_vision(snprintf(msg, 255, "\n$HIW$Nһ�����ȣ�ʦ���ǣ������ͣ�",me->name(1)), this);
		message_vision("��Ӱ�����У���ǰ�����Ͷ�ʱһ�䣡\n", this);
		switch(random(9))
		{
		case 0:
			message_vision("$HIR��ֻ������һ�䣬���岻�ɵĿ����������λ������һ��������������ŵ�����Ҷ��ֱ���������",this);
			if(random(2))
				message_vision("$YEL�㲻�Ų�æ������ȫ�ĵط�.",this);
			else
				message_vision("$HIR�����������ܣ��Ѿ����ݶ�ҶƬ���ˡ�",this);
			break;
		case 1:
			message_vision("$HIR����һ�䣬�������������λ�����Զ������һ�����ǣ�ֱ���������",this);
			if(random(2))
				message_vision("$HIRֻ������������һ����������һ�����춯�صľ޺�, ���Ǹ�����ķ����ˡ�",this);
			else
				message_vision("$HIRɲ�Ǽ䣬������һ�ű���������ţ�������������ϡ�",this);
			break;
		case 2:
			message_vision("$HIR�����ǰһ������Ȩ��λת�������ǰ�����д����������죬����һ�˽�һ�ˣ�ֱ����ӿ����",this);
			if(random(2))
				message_vision("$YEL�������񹦣������α�ȫ�����ױܿ������ˡ�",this);
			else
				message_vision("$HIRֻ���㱻���˴�����ֲ�����������Ѫ��",this);
			break;			
		case 3:
			message_vision("$HIR��ֱ�ӳ������λ��ȥ��������ǰ�������ɲʱ�䣬ɶҲ�������ˡ�",this);
			if(random(2))
				message_vision("$YEL��˫�ֽ���̫��Ѩ�����ڿ�������Χ���龰��",this);
			else
				message_vision("$HIRֻ�������һ�У�˫����������Ѫ��",this);
			break;
		case 4:
			message_vision("$HIRͻȻ�����������һת��ֱ���������Ȩ��λ��һ˲�䣬��������ֱ���������",this);
			if(random(2))
				message_vision("$YELֻ����һ���������ֱ�������ȥ�����������顣",this);
			else
				message_vision("$HIR������޷����������������⡣",this);
			break;
		case 5:
			message_vision("$HIR������˿�����λ������ð���˰˸�ʯ�񣬰�������Χס��",this);
			if(random(2))
				message_vision("$YELֻ���㹥��󷽵�ʯ��˲��˸�ʯ����ʧ����Ӱ�٣�ԭ���ǻþ���",this);
			else
				message_vision("$HIR�����󷽵�ʯ�������������ǣ������ͷ�����ǣ������ڵء�",this);
			break;
		case 6:
			message_vision("$HIR������һ�����ƽ���������λ�����ϵ��Ӳ�ͻȻ�䳤��֣������ذ����ס��",this);
			if(random(2))
				message_vision("$YEL��ʹ����һ�н���ѿǣ��������ӲݵĲ��ơ�",this);
			else
				message_vision("$HIR�㲻�����ѱ��Ӳݲ��ô�����������Ԫ�����ˡ�",this);
			break;
		case 7:
			message_vision("$HIR�������������λ��������������������ɹ�����",this);
			if(random(2))
				message_vision("$YEL�㲻�Ų�æ�������񹦣�ֻ���������γ�һ���ܴ�ķ����֣�������������Ӱ�졣",this);
			else
				message_vision("$HIR�����Ա�һԾ��ͼ���������֪�Ա�Ҳ�л����㱻����ײ�����š�",this);
			break;
		case 8:
			message_vision("$HIR��Ȼ��ǰģ�����壬ԭ��������������λ����ض�������ء�",this);
			if(random(2))
				message_vision("$YELֻ������ӯ�����˼��£�����������ص��˰�ȫ�ط���",this);
			else
				message_vision("$HIR��һ��С��̤�����󣬺ܿ��������ȥ����׽ס�Աߵ���֧�ò����ײ�����������ء�",this);
			break;
		}
		break;
	case 3:
		if(EQUALSTR(who->querystr("nickname"), "������"))
			message_vision(snprintf(msg, 255, "\n$HIW%s�����϶��վ�������ࡱ֮λ���Ʒ��У�����̷������Ҳ��ռ����λ��",who->name(1)), this);
		else
		{
			message_vision(snprintf(msg, 255, "$HIR$N������%sʦ�ܣ���Ҫ̰�������˻������λ��",who->name(1)), this);
	
			for(idx=random(6)+1;idx<6;idx++)
			{
				if(idx!=obj->query("zheng/friend1_idx")&& idx!=obj->query("zheng/friend2_idx")&&idx!=obj->query("zheng/friend3_idx"))
				{
					if(EQUALSTR(obj->querystr("zheng/friend1_name"), who->name(1)))
					{
						destruct(who);
						robber = load_npc(qiangdao[idx-1]);
						obj->set("zheng/friend1_idx",idx);
						obj->set("zheng/friend1_name",robber->name(1));
					}
					else if(EQUALSTR(obj->querystr("zheng/friend2_name"), who->name(1)))
					{
						destruct(who);
						robber = load_npc(qiangdao[idx-1]);
						obj->set("zheng/friend2_idx",idx);
						obj->set("zheng/friend2_name",robber->name(1));
					}
					else
					{
						destruct(who);
						robber = load_npc(qiangdao[idx-1]);
						obj->set("zheng/friend3_idx",idx);
						obj->set("zheng/friend3_name",robber->name(1));
					}
					robber->move(obj);
					message_vision(snprintf(msg, 255, "$HIR$Nת����%s˵����ʦ�ܣ�����ѹס��š�",robber->name(1)), this);
					obj->Join_Team(robber,CFightRoom::FIGHT_TEAM_A);
					break;
				}
			}
		}
		break;
	}
	return 0;
}

NPC_END;




