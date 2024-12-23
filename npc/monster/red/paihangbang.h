//Lanwood 2000-09-17
//�������а�Ķ���
NPC_BEGIN(CNwiz_paihangbang);

protected:
	typedef struct
	{
		int		no;			//�������
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
	set_name("������", "guan tian");

	set("title", "ռ��ʦ");	
	
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

	set_inquiry("��������", do_quiry);

	refresh_board(this, 0, 0);
};

static char * do_quiry(CNpc * ob, CChar * me)
{
	char msg[255], str[40];
	CNwiz_paihangbang * npc = (CNwiz_paihangbang *)ob;

	npc->say("���Ҵ�ָ��/lookboard �Ϳ����ˡ������ӵ�100����ʼ���𣬾���/lookboard 100�����ˣ�", me);
	int mingci = npc->find_me(me);
	if(mingci)
		npc->say(snprintf(msg, 255, "��Ŀǰ���ڵ�%sλ", chinese_number(mingci, str)), me);
	else
		npc->say("�㻹û������", me);

	npc->SendMenu(me);
	return 0;
}

//�����ҵ�����
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
	//�Ƿ��ⲿ����ĸ�������
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

	//�鿴���а� lookboard 100,�ӵ�100������ʾ100����
	if(strcmp(comm, "lookboard") == 0)
	{
		do_lookboard(me, atol(arg), 100);
		return 1;
	}

	return CNpc::handle_action(comm, me, arg);
}

//�鿴���а�
int do_lookboard(CChar * me, int begin, int limit)
{
	char msg[255];
	POSITION p = m_board.FindIndex(begin);
	int i=0;

	tell_object(me, "\n===================  ����������  ================\n");
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

//ˢ�����а�
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
