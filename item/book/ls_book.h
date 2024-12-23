//ls_book.h

//Sample for ITEM: ���¾Ž�����(Lonely_sword_book)
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIls_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���¾Ž�����");	//set item name
	
	set_weight(100);		//set item weight
	
	set("unit", "��");
	set("no_drop","���ǵ����±���������ܶ�ʧ��");
	set("no_put","���ǵ����±���������ܶ�ʧ��");
	set("no_get",1);
	set("no_steal",1);
	set("long","���¾Ž���������ֻ����ϰ(yanxi)��");
	set("value", 1000);
	set("material", "paper");
	set("master_id","npc");
	
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "yanxi") == 0)
		return study(me);
	return 0;
}

int study(CChar * me)
{
    int myskill, cost;
	
    cost=20;      //ÿ��һ�κ�20��
    myskill=me->query_skill("lonely_sword", 1);
    if (!me->query_skill("literate", 1)||me->query_skill("literate",1) < 100)
        return notify_fail("���ս��ף���ʲô����������");
	
    if (me->is_busy())
        return notify_fail("��������æ���ء�");
	
    if (me->is_fighting() )
        return notify_fail("���޷���ս����ר�������ж���֪��");
	
    if (me->query_combat_exp() < 50000)
        return notify_fail("���ʵս���鲻�㣬����ѧ���¾Ž���");
	
    if (myskill>299)
        return notify_fail("���ж���һ���������������˵�Ķ�����Զ�̫ǳ�ˡ�");
	
    if (myskill<75)
        return notify_fail("�����һ����,����ȴ�����ջ�");
	
	set("book_verb", "yanxi");

    if (me->query("hp")>cost )
    {
		if (myskill*myskill*myskill/10>me->query_combat_exp() )
		{
			tell_object(me,"Ҳ����ȱ��ʵս���飬��Զ��¾Ž���������˵�Ķ��������޷���ᡣ");
		}
		else
		{
			tell_object(me,"���ж��йض��¾Ž������ϵļ��ɣ��ƺ��е��ĵá�");
			me->improve_skill("lonely_sword", me->query_skill("literate", 1)+me->query("int"));
		}
    }
    else
    {
		cost=me->query("hp");
		tell_object(me,"�����ڹ���ƣ�룬�޷�ר�������ж���֪��");
    }
    me->receive_damage("hp", cost );
    return 1;
}

virtual void owner_is_killed(CChar * me)
{
	if(me) 
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	destruct(this);
}

/**********************
//���¾Ž�����(Lonely_sword_book)
// ls_book.c
// Date: Oct.6 1997 by That

  #include <ansi.h>
  inherit ITEM;
  inherit F_AUTOLOAD;
  int do_study(string);
  int study(object me, string arg)
  {
  object where = environment(me);
  object ob;
  int myskill, cost;
  
    cost=20;                                            //ÿ��һ�κ�20��
    myskill=me->query_skill("lonely_sword", 1);
    if (!arg || !objectp(ob = present(arg, me)))
	return notify_fail("��Ҫ��ʲô��\n");
    if (!me->query_skill("literate", 1)||me->query_skill("literate",1) < 100)
	return notify_fail("���ս��ף���ʲô����������\n");
    if (me->is_busy())
	return notify_fail("��������æ���ء�\n");
    if (me->is_fighting() )
	return notify_fail("���޷���ս����ר�������ж���֪��\n");
    if (me->query_combat_exp() < 50000)
	return notify_fail("���ʵս���鲻�㣬����ѧ���¾Ž���\n");
    if (myskill>299)
	return notify_fail("���ж���һ���������������˵�Ķ�����Զ�̫ǳ�ˡ�\n");
    if (myskill<75)
	return notify_fail("�����һ����,����ȴ�����ջ�\n");
    if (me->query("hp")>cost )
    {
	if (myskill*myskill*myskill/10>me->query_combat_exp() )
	{
	printf("Ҳ����ȱ��ʵս���飬��Զ��¾Ž���������˵�Ķ��������޷���ᡣ\n");
	}
	else
	{
	printf("���ж��йض��¾Ž������ϵļ��ɣ��ƺ��е��ĵá�\n");
	me->improve_skill("lonely_sword", me->query_skill("literate", 1)+me->query("int"));
	}
    }
    else
    {
	cost=me->query("hp");
	write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
    }
    me->receive_damage("hp", cost );
    return 1;
	}
	virtual void create()
	{
	set_name(HIG"���¾Ž�����"NOR, ({ "lonely_sword_book","ls_book" }));
	set_weight(100);
	if( clonep() )
	set_default_object(__FILE__);
	else
	{
	set("unit", "��");
	set("no_drop","���ǵ����±���������ܶ�ʧ��");
	set("no_put","���ǵ����±���������ܶ�ʧ��");
	set("no_get",1);
	set("no_steal",1);
	set("long","���¾Ž���������ֻ����ϰ(yanxi)��\n");
	set("value", 1000);
	set("material", "paper");
	set("master_id","npc");
	}
	}
	
	  void init()
	  {
	  add_action("do_study","yanxi");
	  }
	  
		int do_study(string arg)
		{
        object me,ob;
        me=this_player();
        ob=this_object();
		
		  write("�ۣ�����ǧ�Ŷ����Ľ�����");
		  study(me,arg);
		  return 1;
		  }
		  
			string query_autoload()
			{
			object me;
			me = this_object();
			return me->query("master_id");
			}
			void autoload(string arg)
			{
			set("master_id",arg);
			}
			void owner_is_killed()
			{
			write(HIY"ֻ����ǰ���һ��...������.....\n"NOR);
			destruct(this_object());
			}
*************************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp