//monster_searcher2.h
//NPC �غ�����

NPC_BEGIN(CNmonster_searcher2);

typedef struct{
	int	search_id;
	int has_search;
	string enter_door;		
}path_t;

typedef map<string, path_t *, less<string> > MAP2PATH;
typedef MAP2PATH::iterator iterator_path;

MAP2PATH m_search;

virtual void create()
{
	set_name( "�غ�����", "zongheng tianxia");
	
	set("max_hp", 30000000+random(10000000));
	set("hp",query("max_hp"));
	set("max_mp", 20000);
	set("mp",20000);
	set("mp_factor", 160);
	set("combat_exp", 35000000+random(10000000));
	set("no_duo",1);
			
	set("chat_chance", 30);
	set("chat_chance_combat", 20);

	set("no_kill",1);
	set("no_���־�",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_ǧ���׹�",1);
	set_temp("apply/no_��˼����",1);
	set_temp("apply/no_�ƺ�����",1);
	set_temp("apply/no_���־�",1);
	set_temp("apply/no_�������",1);
	set_temp("apply/no_ƴ��",1);
	set_temp("apply/no_��Ѫ��",1);
	
	set("bigboss",1);
	set("kkk",1);

	set("apply/armor", 380);
    set("apply/damage", 200);
	
};

//��һ����Ҫ����������ǲ�ͣ����·��
virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		switch(random(10))
		{
		case 1:
			command("chat 0 $HIR��������Ҳң����껹���޴�����");
			break;
		case 3:
			command("chat 0 $HIR���������������Ҳ����ҵģ�");
			break;
		case 5:
			command("chat 0 $HIR��������Ҳ��Ĳ�����˼��͵���ı���Ҳ̫̫̫���ˣ�");
			break;
		case 7:
			command("chat 0 $HIR�����ʶ���˲�����ν�ĸ��֣��������ǵĹ���Ҳ�����һ����");
			break;
		}
		break;
	case 1:
        if(search())
		{
			do_die();		//������ϣ��Զ�����
			return 0;
		}
		break;
	}
	return 0;
}

int search()
{
	char msg[80];
	
	if(! m_pEnvironment->Query(IS_ROOM)) return 0;
	
	CRoom * room = (CRoom *)m_pEnvironment;
	DTEXITLIST * list = room->query_exits();
	
	path_t * node;
	
	node = get_path(room->querystr("base_name"));
	
	int doors = list->GetCount();
	
	if(! querystr("start_point")[0])
		set("start_point", room->querystr("base_name"));
	
	if(node->has_search)
	{
		//�ж��Ƿ����
		if(EQUALSTR(room->querystr("base_name"), querystr("start_point")))
		{
			command("chat 0 $HIR���������ݺὭ����ʮ�أ���Ȼû�����Ϲ����֣�");
			return 1;
		}
		
		//command("chat 0 �Ѿ��������ˣ�");
		//�Ҹ���·��
		command(snprintf(msg, 80, "go 0 %s", node->enter_door.c_str()));
		
		switch(random(10))
		{
		case 1:
			command("chat 0 $HIR��������Ҳң����껹���޴�����");
			break;
		case 3:
			command("chat 0 $HIR���������������Ҳ����ҵģ�");
			break;
		case 5:
			command("chat 0 $HIR��������Ҳ��Ĳ�����˼��͵���ı���Ҳ̫̫̫���ˣ�");
			break;
		case 7:
			command("chat 0 $HIR�����ʶ���˲�����ν�ĸ��֣��������ǵĹ���Ҳ�����һ����");
			break;
		}
		
		return 0;
	}
	
	if(doors)
	{
		
		node->search_id++;
		
		if(node->search_id >= doors)
			node->search_id = 0;
		
		POSITION p = list->FindIndex(node->search_id);
		CDoor * dir = list->GetAt(p); 
		
		if(dir->querystr("id") == node->enter_door)
		{
			node->has_search = 1;
		}
		
		command(snprintf(msg, 80, "go 0 %s", dir->querystr("id")));
		
		room = (CRoom *)environment();
		
		node = get_path(room->querystr("base_name"));
		
		if(! node->enter_door.length())
		{
			node->enter_door = dir->querystr("next_door");
			list = room->query_exits();
			for(int i=0; i<list->GetCount(); i++)
			{
				p = list->FindIndex(i);
				dir = list->GetAt(p);
				if(dir->querystr("id") == node->enter_door)
				{
					node->search_id = i;
					return 0;
				}
				
			}
			//command(snprintf(msg, 80, "chat 0 ����%s�Ҳ�����ȷ����%s��", room->querystr("base_name"), node->enter_door.c_str()));
		}
		
		return 0;
	}
	
	//command("chat 0 �ҽ���ʧ�ܵķ����ˣ�");
	return 0;
}

path_t * get_path(string room_name)
{
	if(m_search.find(room_name) == m_search.end())
	{
		path_t * node = new path_t;
		
		node->search_id = 0;
		node->has_search = 0;
		node->enter_door = "";
		
		m_search[room_name] = node;
		return node;
	}
	
	return m_search[room_name];
}

void clear_path()
{
	iterator_path p;
	
	for(p = m_search.begin(); p!=m_search.end(); p++)
		delete p->second;
	
	m_search.clear();
}

virtual void do_die()
{
	clear_path();
	CNpc::die();
}

virtual char * chat_msg_combat()
{
	set("mp",20000);
	set("gender", "����");
	set("age", 30+random(80));
	
	CContainer * weapon = query_weapon();
	if(weapon)
	{
		destruct(weapon);
	}
	
	switch(random(17))
	{
	case 1:
		set_skill("force", 200+random(200));
		set_skill("taiji_shengong", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("tiyunzong", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("taiji_quan", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("taiji_jian", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("taiji_dao", 200+random(200));
		set_skill("taoism", 200+random(200));
		set_skill("literate", 200+random(200));
		
		map_skill("force", "taiji_shengong");
		map_skill("dodge", "tiyunzong");
		map_skill("unarmed", "taiji_quan");
		map_skill("parry", "taiji_jian");
		map_skill("sword", "taiji_jian");
		map_skill("blade", "taiji_dao");
		message_vision("\n\n$HIR$N΢һ��������̫���񹦣�ȫ����������������޷����裬�������ˡ�\n\n", this);
		break;
	case 2:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("cuff", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("finger", 200+random(200));
		set_skill("kurong_changong", 200+random(200));
		set_skill("tiannan_step", 200+random(200));
		set_skill("jinyu_quan", 200+random(200));
		set_skill("wuluo_zhang", 200+random(200));
		set_skill("duanjia_sword", 200+random(200));
		set_skill("sun_finger", 200+random(200));
		set_skill("lm_shangyang", 200+random(200));	
		set_skill("literate", 200+random(200));
		
		map_skill("force", "kurong_changong");
		map_skill("dodge", "tiannan_step");
		map_skill("finger", "sun_finger");
		map_skill("cuff", "jinyu_quan");
		map_skill("strike", "wuluo_zhang");
		map_skill("parry", "sun_finger");
		map_skill("sword", "duanjia_sword");
		map_skill("staff", "duanjia_sword");
		
		prepare_skill("cuff", "jinyu_quan");
		prepare_skill("strike", "wuluo_zhang");
		carry_object("sword_2")->wield();
		message_vision( "\n\n$HIR$N��������������������������α�ȫ��\n\n" ,this);
		break;
	case 3:
		set_skill("persuading", 200+random(200));
		set_skill("throwing", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("finger", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("mahayana", 200+random(200));
		set_skill("buddhism", 200+random(200));
		set_skill("jinding_zhang", 200+random(200));
		set_skill("tiangang_zhi", 200+random(200));
		set_skill("huifeng_jian", 200+random(200));
		set_skill("yanxing_dao", 200+random(200));
		set_skill("zhutian_bu", 200+random(200));
		set_skill("linji_zhuang", 200+random(200));
		
		map_skill("force","linji_zhuang");
		map_skill("finger","tiangang_zhi");
		map_skill("dodge","zhutian_bu");
		map_skill("strike","jinding_zhang");
		map_skill("sword","huifeng_jian");
		map_skill("blade","yanxing_dao");
		map_skill("parry","huifeng_jian");
		if(random(2))
			carry_object("sword_2")->wield();
		else
			carry_object("blade_2")->wield();
		set("gender", "Ů��");
		message_vision("\n\n$HIR$N΢һ���������ټ�ׯ��һ�����ȣ�\n\n" , this);
		break;
	case 4:
		set_skill("persuading", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("hand",200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("hamagong", 200+random(200));
		set_skill("chanchu_bufa", 200+random(200));
		set_skill("shexing_diaoshou", 200+random(200));
		set_skill("lingshe_zhangfa", 200+random(200));
		set_skill("xunshou_shu",200+random(200));
		
		map_skill("force", "hamagong");
		map_skill("dodge", "chanchu_bufa");
		map_skill("unarmed", "shexing_diaoshou");
		map_skill("hand", "shexing_diaoshou");
		map_skill("parry", "lingshe_zhangfa");
		map_skill("staff", "lingshe_zhangfa");
		carry_object("zijin_staff")->wield();
		message_vision("\n\n$HIR$N����˫�ֳŵص��������˾�������ʱ��Ϣ������������������\n\n", this);
		break;
	case 5:
		set_skill("force", 200+random(200));           
		set_skill("huntian_qigong", 200+random(200));    
		set_skill("unarmed", 200+random(200));           
		set_skill("xianglong_zhang", 200+random(200));   
		set_skill("dodge", 200+random(200));      	     
		set_skill("xiaoyaoyou", 200+random(200));      
		set_skill("parry", 200+random(200));           
		set_skill("staff", 200+random(200));            
		set_skill("dagou_bang", 200+random(200));        
		set_skill("begging", 200+random(200));           
		set_skill("xunshou_shu", 200+random(200));
		
		map_skill("force", "huntian_qigong");
		map_skill("unarmed", "xianglong_zhang");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("parry", "xianglong_zhang");
		map_skill("staff", "dagou_bang");
		
		prepare_skill("unarmed", "xianglong_zhang");
		carry_object("zijin_staff")->wield();
		message_vision("\n\n$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������졣\n\n" , this);	
		break;
	case 6:
		set_skill("force", 200+random(200));
		set_skill("yunv_xinfa", 200+random(200));	
		set_skill("seaforce", 200+random(200));		
		set_skill("sword", 200+random(200));
		set_skill("yunv_jian", 200+random(200));
		set_skill("smithsword",200+random(200));	
		set_skill("dodge", 200+random(200));
		set_skill("xianyun_bufa", 200+random(200));	
		set_skill("parry", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("meinv_quan", 200+random(200));    
		set_skill("anranxiaohun_zhang", 200+random(200));
		set_skill("tianluo_diwang", 200+random(200));
		set_skill("literate", 200+random(200));
		
		map_skill("force", "seaforce");
		map_skill("sword", "smithsword");
		map_skill("dodge", "xianyun_bufa");
		map_skill("parry", "anranxiaohun_zhang");
		map_skill("unarmed", "anranxiaohun_zhang");
		carry_object("sword_2")->wield();
		message_vision( "\n\n$HIR$N������ķ�������΢չ��������ˮ��Ļ���������һƬ��Ӱ���������飡\n\n" ,this );
		break;
	case 7:
		set_skill("cuff", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("strike",200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("zixia_shengong", 200+random(200));
		set_skill("poyu_quan", 200+random(200));
		set_skill("huashan_sword", 200+random(200));
		set_skill("hunyuan_zhang", 200+random(200));
		set_skill("lonely_sword", 200+random(200));
		set_skill("huashan_shenfa",200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("zhengqijue", 200+random(200));
		
		map_skill("cuff", "poyu_quan");
		map_skill("force", "zixia_shengong");
		map_skill("dodge", "huashan_shenfa");
		map_skill("parry", "lonely_sword");
		map_skill("sword", "lonely_sword");
		map_skill("strike", "hunyuan_zhang");
		message_vision("\n\n$HIR$N΢һ����������ϼ�񹦣���ת��ȥ������ͻȻ������ʢ��ֻ��������һ�ּ�����ת�������������ֻظ��糣��\n\n" , this);
		carry_object("sword_2")->wield();
		break;
	case 8:
		set_skill("force", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("hand",200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword",200+random(200));
		
		set_skill("zhemei_shou",200+random(200));
		set_skill("liuyang_zhang",200+random(200));
		set_skill("tianyu_qijian",200+random(200));
		set_skill("yueying_wubu",200+random(200));
		set_skill("bahuang_gong", 200+random(200));
		
		map_skill("force", "bahuang_gong");
		map_skill("strike","liuyang_zhang");
		map_skill("dodge", "yueying_wubu");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("strike","liuyang_zhang");
		map_skill("hand", "zhemei_shou");
		map_skill("parry", "liuyang_zhang");
		map_skill("sword","tianyu_qijian");
		
		prepare_skill("strike","liuyang_zhang");
		prepare_skill("hand","zhemei_shou");
		carry_object("sword_2")->wield();
		message_vision("\n\n$HIR$N����Ϣ��������˻�����Ψ�Ҷ��𹦣�ֻ��һ��������������\n\n", this);
		break;
	case 9:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("jiuyang_shengong", 200+random(200));
		set_skill("lingfa", 200+random(200));
		set_skill("shenghuo_lingfa", 200+random(200));
		set_skill("qiankun_danuoyi", 200+random(200));
		set_skill("shenghuo_xinfa", 200+random(200));
		
		map_skill("parry", "qiankun_danuoyi");
		map_skill("force", "jiuyang_shengong");
		map_skill("dodge", "qiankun_danuoyi");
		map_skill("lingfa", "shenghuo_lingfa");
		message_vision(	"\n\n$HIR$N΢һ������������񹦣�ȫ��ǽڷ���һ�󱬶��������, ��ȫ��Ǳ�ܾ�������\n\n "  , this);
		break;
	case 10:
		set_skill("force", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("unarmed",200+random(200));
		set_skill("strike",200+random(200));
		set_skill("finger",200+random(200));
		set_skill("literate",200+random(200));
		set_skill("taoism",200+random(200));
		set_skill("xiantian_qigong", 200+random(200));
		set_skill("xiantian_gong", 200+random(200));
		set_skill("quanzhen_jianfa",200+random(200));  
		set_skill("quanzhen_jian",200+random(200));  
		set_skill("jinyan_gong", 200+random(200));   
		set_skill("haotian_zhang", 200+random(200));   
		set_skill("sun_finger",200+random(200)); 
		
		map_skill("force", "xiantian_qigong");
		map_skill("sword", "quanzhen_jianfa");
		map_skill("dodge", "jinyan_gong");
		map_skill("parry", "quanzhen_jianfa");
		map_skill("strike", "haotian_zhang");
		map_skill("finger","sun_finger");
		
		prepare_skill("finger","sun_finger");
		prepare_skill("strike","haotian_zhang");
		carry_object("sword_2")->wield();
		message_vision("\n\n$HIR$N΢һ��������������������׳�������ȫ���������������\n\n"  ,this);
		break;
	case 11:
		set_skill("buddhism", 200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("claw", 200+random(200));
		set_skill("club", 200+random(200));
		set_skill("cuff", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("finger", 200+random(200));
		set_skill("force", 200+random(200));
		set_skill("hand", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("whip", 200+random(200));
		
		set_skill("banruo_zhang", 200+random(200));
		set_skill("cibei_dao", 200+random(200));
		set_skill("damo_jian", 200+random(200));
		set_skill("fengyun_shou", 200+random(200));
		set_skill("fumo_jian", 200+random(200));
		set_skill("hunyuan_yiqi", 200+random(200));
		set_skill("jingang_quan", 200+random(200));
		set_skill("longzhua_gong", 200+random(200));
		set_skill("luohan_quan", 200+random(200));
		set_skill("nianhua_zhi", 200+random(200));
		set_skill("pudu_zhang", 200+random(200));
		set_skill("qianye_shou", 200+random(200));
		set_skill("sanhua_zhang", 200+random(200));
		set_skill("riyue_bian", 200+random(200));
		set_skill("shaolin_shenfa", 200+random(200));
		set_skill("weituo_gun", 200+random(200));
		set_skill("wuchang_zhang", 200+random(200));
		set_skill("xiuluo_dao", 200+random(200));
		set_skill("yingzhua_gong", 200+random(200));
		set_skill("yijinjing", 200+random(200));
		set_skill("yizhi_chan", 200+random(200));
		set_skill("zui_gun", 200+random(200));
		
		map_skill("blade", "cibei_dao");
		map_skill("claw", "longzhua_gong");
		map_skill("club", "wuchang_zhang");
		map_skill("cuff", "luohan_quan");
		map_skill("dodge", "shaolin_shenfa");
		map_skill("finger", "yizhi_chan");
		map_skill("force", "yijinjing");
		map_skill("hand", "fengyun_shou");
		map_skill("parry", "nianhua_zhi");
		map_skill("staff", "weituo_gun");
		map_skill("strike", "banruo_zhang");
		map_skill("sword", "fumo_jian");
		map_skill("whip", "riyue_bian");
		
		prepare_skill("finger", "yizhi_chan");
		prepare_skill("strike", "banruo_zhang");
		message_vision("\n\n$HIR$N���һҧ�����һ����Ѫ�������׽���ѽ�ȫ��Ǳ����������\n\n", this);

		switch(random(4))
		{
		case 0:
			carry_object("sword_2")->wield();
			break;
		case 1:
			carry_object("blade_2")->wield();
			break;
		case 2:
			carry_object("changbian")->wield();
			break;
		case 3:
			carry_object("zijin_staff")->wield();
			break;
		}

		break;
	case 12:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("strike", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("sword", 200+random(200));
		set_skill("literate", 200+random(200));
		
		set_skill("shenlong_xinfa", 200+random(200));
		set_skill("yixingbu", 200+random(200));
		set_skill("shenlong_bashi", 200+random(200));
		set_skill("huagu_mianzhang", 200+random(200));
		set_skill("shedao_qigong", 200+random(200));
		
		map_skill("force", "shenlong_xinfa");
		map_skill("dodge", "yixingbu");
		map_skill("unarmed", "shenlong_bashi");
		map_skill("strike", "huagu_mianzhang");
		map_skill("parry", "shedao_qigong");
		map_skill("sword", "shedao_qigong");
		
		prepare_skill("strike", "huagu_mianzhang");
		prepare_skill("unarmed", "shenlong_bashi");
		message_vision( "\n\n$HIR$N�������һ��������Ȼ���쳤Х��������У�����������Ǹ���ţ�����\n\n"  , this);

		break;
	case 13:
		set_skill("force", 200+random(200));            
		set_skill("claw", 200+random(200));              
		set_skill("hand", 200+random(200));            
		set_skill("finger", 200+random(200));          
		set_skill("unarmed", 200+random(200));         
		set_skill("strike", 200+random(200));          
		set_skill("leg",200+random(200));	           
		set_skill("dodge", 200+random(200));           
		set_skill("parry", 200+random(200));            
		set_skill("sword", 200+random(200));           
		
		set_skill("anying_fuxiang", 200+random(200));    
		set_skill("tanzhi_shentong", 200+random(200));   
		set_skill("xuanfeng_leg", 200+random(200));      
		set_skill("luoying_shenzhang", 200+random(200));     
		set_skill("bibo_shengong", 200+random(200));     
		set_skill("luoying_shenjian", 200+random(200));  
		set_skill("yuxiao_jianfa", 200+random(200));       
		set_skill("lanhua_shou", 200+random(200));       
		set_skill("qimen_wuxing",200+random(200));       
		set_skill("literate", 200+random(200));           
		
		map_skill("force"  , "bibo_shengong");
		map_skill("finger" , "tanzhi_shentong");
		map_skill("hand"   , "lanhua_shou");
		map_skill("unarmed", "luoying_shenzhang");
		map_skill("strike", "luoying_shenzhang");
		map_skill("leg", "xuanfeng_leg");
		map_skill("dodge"  , "anying_fuxiang");
		map_skill("parry"  , "tanzhi_shentong");
		map_skill("sword"  , "tanzhi_shentong");
		
		prepare_skill("finger", "tanzhi_shentong");
		prepare_skill("hand", "lanhua_shou");
		message_vision("\n\n$HIR$N���һҧ�����һ����Ѫ������̲����ѽ�ȫ��Ǳ����������\n\n"  , this);

		carry_object("sword_2")->wield();
		break;
	case 14:
		set_skill("force", 200+random(200));
		set_skill("beiming_shengong", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("lingboweibu", 200+random(200));
		set_skill("unarmed", 200+random(200));
		set_skill("liuyang_zhang", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("blade", 200+random(200));
		set_skill("xiaoyao_dao", 200+random(200));
		set_skill("zhemei_shou", 200+random(200));
		set_skill("hand", 200+random(200));
		set_skill("literate", 200+random(200));
		
		map_skill("force", "beiming_shengong");
		map_skill("dodge", "lingboweibu");      
		map_skill("hand", "zhemei_shou");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("parry", "xiaoyao_dao");
		map_skill("blade", "xiaoyao_dao");
		
		prepare_skill("hand","zhemei_shou");
		prepare_skill("unarmed","liuyang_zhang");
		message_vision("\n\n$HIR$N˫��ƽ�ٹ���������ڤ�񹦣�ȫ�������ھ���֮�У�\n\n", this);

		carry_object("blade_2")->wield();
		break;
	case 15:
		set_skill("throwing", 200+random(200));
		set_skill("feixing_shu", 200+random(200));        
		set_skill("force", 200+random(200));
		set_skill("huagong_dafa", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("zhaixinggong", 200+random(200));
		set_skill("strike",200+random(200));
		set_skill("xingxiu_duzhang", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("staff", 200+random(200));
		set_skill("tianshan_zhang", 200+random(200));
		set_skill("literate", 200+random(200));
		set_skill("sanyin_wugongzhao", 200+random(200));
		set_skill("claw", 200+random(200));
		set_skill("poison", 200+random(200));
		
		map_skill("force", "huagong_dafa");
		map_skill("dodge", "zhaixinggong");
		map_skill("strike", "xingxiu_duzhang");
		map_skill("parry", "feixing_shu");
		map_skill("staff", "tianshan_zhang");
		map_skill("unarmed", "xingxiu_duzhang");
		map_skill("claw", "sanyin_wugongzhao");
		
		prepare_skill("unarmed", "xingxiu_duzhang");
		prepare_skill("claw", "sanyin_wugongzhao");
		message_vision("\n\n$HIR$N���һҧ�����һ�ڶ�Ѫ�����𻯹����ѽ�ȫ��Ǳ����������\n\n", this);

		carry_object("zijin_staff")->wield();
		break;	
	case 16:
		set_skill("force", 200+random(200));
		set_skill("dodge", 200+random(200));
		set_skill("parry", 200+random(200));
		set_skill("claw",200+random(200));
		
		set_skill("wuwen_zhua",200+random(200));
		set_skill("guimei_shenfa",200+random(200));
		set_skill("wudu_shengong", 200+random(200));
		set_skill("tangshoudao", 200+random(200));
		
		map_skill("force", "wudu_shengong");
		map_skill("dodge", "guimei_shenfa");
		map_skill("parry", "tangshoudao");
		map_skill("claw", "wuwen_zhua");
		prepare_skill("claw", "wuwen_zhua");

		if(random(2))
			message_vision("\n\n$HIR$N˫�ֺ�ʮ����¶��֮ɫ��ֻ��һƬѩ��Ʈ������\n\n", this);
		else
			message_vision("\n\n$HIR$N����һ����һ�������Ե������𡭡�\n\n", this);
		break;
	}
	return 0;
}

virtual void die()
{
	CContainer * obj = environment();
	CContainer * bot;
	char msg[255];
	set("grant", 99);
	set_name( "����ʹ��", "kuaile shizhe");
	g_Channel.do_channel(this, NULL, "news",  "$HIR�ڴ�ҵĺ���Χ���£��������������ǵĽ������");
	g_Channel.do_channel(this, NULL, "news",  "$HIR���ֽ�����ͬ�ڣ�");
	g_Channel.do_channel(this, NULL, "news",  "$HIR���س����������й�����Աף��ҽ��տ��֣�");
	set_name( "�غ�����", "zongheng tianxia");
	g_player();

	static char baowu[37][20]={"taibaizao","38huoqiang","diaojiandai","jinhuantoushi","btzheng",
		"xuantiebishou","bolanxie","haoseshan","xiantianyu","poliquan","fannaomao","shajiezhi","tiancanbaojia",
		"newyear","newyear1","zidiaopifeng","liaochengpao","dagoubang","yinguozhu","dulonglian","shenshe_staff",
		"ruanweijia","zhangmenhuan","yinmopao","conglinjian",
		"kuihuaao","jinlianxie","fengyizhen","xuanwupao","yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie",
		"zueiyupao","hanyuzhi","lantiandai"};

	for(int i=0;i<random(5)+3;i++)
	{
		if(random(5)>2)
			bot = load_item(baowu[random(37)]);
		bot = load_item("dazongzi");
		if(random(100)>85)
			bot->set("����",1);
		bot->move(obj);
	}
	for(int i=0;i<random(5)+325;i++)
	{
		int index=random(MAX_ROOM_NUM);
		//bot = load_item(baowu[random(37)]);
		bot = load_item("dazongzi");
		if(random(100)>85)
			bot->set("����",1);
		obj = load_room(global_room_name[index]);
		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s�ƶ�����%s��",bot->name(1),obj->querystr("base_name")));
		bot->move(obj);
	}
	CNpc::die();
}

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;
	CContainer * bot;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		if(obj->query("level")>10 && obj->query("age")>16 && obj->query("combat_exp")>5000)
		{
			char msg[255];
			
			snprintf(msg, 255, "$HIR\n����Ʈ��������һ���������ƫ����������Ļ��С���\n���һ����ԭ����һ��������������ӣ�����������Ҷ����һ�����㡣\n\n");
			
			tell_object(obj,msg);
			bot = load_item("dazongzi");
			if(random(100)>50)
				bot->set("����",1);
			bot->move(obj);
			//load_item("dazongzi")->move(obj);
		}
    }
    
	return 1;
}

NPC_END;