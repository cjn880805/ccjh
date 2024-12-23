//Lanwood 2000-09-17
//更新排行榜的东东
NPC_BEGIN(CNwiz_paihangbang);

protected:
	typedef struct
	{
		int		no;			//排名序号
		char	id[20];
		char	name[40];
		char	family[20];
		LONG	exp;
	}t_item;

	typedef CList<t_item *, t_item *>t_board;

	t_board		m_board;

public:

void create()
{
	set_name("观天眼", "guan tian");

	set("title", "占星师");	
	
//-------------------------------------------
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("icon",taoist);	
	
	set("max_hp", 30000);
	set("mp", 20000);
	set("max_mp", 20000);
	set("mp_force", 300);
	set("combat_exp", 7000000);
	set("score", 1200000);

	set_skill("force", 320);
	set_skill("taiji_shengong", 320);
	set_skill("dodge", 300);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 350);
	set_skill("taiji_quan", 350);
	set_skill("parry", 300);
	set_skill("sword", 330);
	set_skill("taiji_jian", 330);
	set_skill("blade", 300);
	set_skill("taiji_dao", 300);
	set_skill("taoism", 350);
	set_skill("literate", 300);

	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("blade", "taiji_dao");
	
	set("class", "taoist");

	set("chat_chance_combat", 30);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();

	set_inquiry("江湖排名", do_quiry);

	refresh_board(this, 0, 0);
};

static char * do_quiry(CNpc * ob, CChar * me)
{
	char msg[255], str[40];
	CNwiz_paihangbang * npc = (CNwiz_paihangbang *)ob;

	npc->say("对我打指令/lookboard 就可以了。如果想从第100名开始看起，就敲/lookboard 100。好运！", me);
	int mingci = npc->find_me(me);
	if(mingci)
		npc->say(snprintf(msg, 255, "你目前排在第%s位", chinese_number(mingci, str)), me);
	else
		npc->say("你还没有名次", me);

	npc->SendMenu(me);
	return 0;
}

//返回我的排名
int find_me(CChar * me)
{
	const char * id = me->id(1);
	POSITION p = m_board.GetHeadPosition();
	while(p)
	{
		t_item * node = m_board.GetNext(p);
		if(strcmp(node->id, id) == 0)
			return node->no;
	}

	return 0;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	//是否外部传入的更新数据
	if(! me)
	{
		if( strcmp(comm, "update") != 0) return 0;

		int mingci;
		LONG exp;
		char myid[20], myname[40], family[40];
				
		sscanf(arg, "%d %s %s %s %ld", &mingci, myid, myname, family, &exp);
		add_board(mingci + 1, myid, myname, family, exp);
		return 1;
	}

	//查看排行榜 lookboard 100,从第100名起显示100名。
	if(strcmp(comm, "lookboard") == 0)
	{
		do_lookboard(me, atol(arg), 100);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//查看排行榜
int do_lookboard(CChar * me, int begin, int limit)
{
	char msg[255];
	POSITION p = m_board.FindIndex(begin);
	int i=0;

	tell_object(me, "\n===================  江湖排名榜  ================\n");
	while(p && i < limit)
	{
		char nameid[80], color[5];
		t_item * node = m_board.GetNext(p);
		sprintf(nameid, "%s(%s)", node->name, node->id);

		if(strcmp(me->id(1), node->id) == 0)
			strcpy(color, "$HIG");
		else
			color[0] = 0;

		if( me->query("grant") >= 70 )
			sprintf(msg, "%s%-8d%-25s%-15s%ld", color, node->no, nameid, node->family, node->exp);
		else
			sprintf(msg, "%s%-8d%-25s%s", color, node->no, nameid, node->family);
		tell_object(me, msg);
		i++;		
	}
	return 1;
}

//刷新排行榜
static void refresh_board(CContainer * ob, LONG param1, LONG param2)
{
	CNwiz_paihangbang * me = (CNwiz_paihangbang *)ob;

#ifdef _SQL_

	me->clear_board();
	paihangbang(me);
	me->call_out(refresh_board, 36000);
#else
	me->handle_action("update", NULL, "12 1100 lanwood taohuadao 124343");
	me->handle_action("update", NULL, "19 1010 lanwood taohuadao 124343");
#endif
}

t_item * add_board(int mingci, const char * myid, const char * myname, const char * family, LONG exp)
{
	t_item * node = new t_item;

	node->no = mingci;
	strncpy(node->id, myid, 20);
	strncpy(node->name, myname, 40);
	strncpy(node->family, family, 20);
	node->exp = exp;

	m_board.AddTail(node);
	return node;
}

void clear_board()
{
	POSITION p = m_board.GetHeadPosition();
	while(p)
	{
		t_item * node = m_board.GetNext(p);
		delete node;
	}

	m_board.RemoveAll();
}

void destructed()
{
	clear_board();
}

NPC_END;
