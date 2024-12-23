//marry_card.h

//Sample for ITEM 礼品盒
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CImarry_card);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "婚约");	//set item name
	
	set_weight(10);
	set("no_get",1);
	set("no_beg",1);
	set("no_put",1);
	set("no_steal",1);
	set("no_drop","你的婚约不能丢弃, 只能去红娘庄解除婚约。");
	set("unit", "本");
	set("material", "paper");
	
};

/*
virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "coupletalk") == 0)
		return do_coupletalk(me);
	if(strcmp(comm, "cm") == 0)
		return do_cemote(me, arg);
	return 0;
}

int do_cemote(CChar *me, string arg)
{
	char cardname[80];
	char target[40];
	MAP2USER * user;
	MAP2USER::iterator p;
	CUser * couple_ob;

	strncpy(cardname, name(1), 80);

	if (sscanf(cardname, "你和%s的婚约" , target) != 1)
		return notify_fail("你没有伴侣.");
	
	user = users();
	for( p = user->begin(); p!= user->end(); p++)
	{
		couple_ob = p->second;
		if(couple_ob->querystr("id") == target)
			break;
		couple_ob = NULL;
	}

	if( !couple_ob )
		return notify_fail("你的伴侣现在听不见你，或者已经离开游戏了。");

	char tmpstr1[5], tmpstr2[5], str1[3], str2[3];
	
	if (couple_ob->querystr("gender") != "女性")
	{
		strcpy(tmpstr1,"老婆"); 
		strcpy(tmpstr2, "老公");
		strcpy(str1, "她"); 
		strcpy(str2, "他");
	} 
	else
	{
		strcpy(tmpstr1,"老公"); 
		strcpy(tmpstr2, "老婆");
		strcpy(str1, "他"); 
		strcpy(str2, "她");
	}
	
	if (arg.length())
	{
		tell_object(me,  "你又深情的想念你的爱侣了。" );
		MessageVision(me, "chat", snprintf(msg, 255, "%s又深情的想念%s的爱侣%s了。", 
			me->name(), str1, couple_ob->name(), me, couple_ob);

		tell_object(couple_ob, snprintf(msg, 255, "%s%s又在深情的想你了", tmpstr1,me->name(1)));
		return 1;
	}

	if (me->environment() == couple_ob->environment() )
	{
		if (arg == "kiss")
		{
			tell_object(me, "你拥住你的爱侣，深深的一吻，许久...许久..." );
			MessageVison(me, "chat", snprintf(msg, 255, "%s拥住%s，深深的一吻。", 
				me->name(), couple_ob->name()), me, couple_ob);

			tell_object(couple_ob, snprintf(msg, 255, "%s%s拥住你，深深的一吻，许久...许久...", tmpstr1, me->name(1)));
		}

		if (arg == "bye")
		{
			tell_object(me,  "你含泪凝望着你的爱侣，哽咽道: 又要分手了，何时才能长相聚不分离呀......" );
			MessageVision(me, "chat", snprintf(msg, 255, "%s拥住%s，深深的一吻。",
				me->name(), couple_ob->name(), me, couple_ob);

			tell_object(couple_ob, snprintf(msg, 255, "%s%s含泪凝望着你，哽咽道: 又要分手了，何时才能长相聚不分离呀......",tmpstr1,me->name(1)));
		}
	}
	
	return 1;
}

int do_coupletalk(CChar * me, char * arg)
{
	char cardname[80], target[40];
	MAP2USER * user;
	iterator_user p;
	CUser * couple_ob;
	
	if (sscanf(cardname, "你和%s的婚约" ,target) != 1)
		return notify_fail("你没有伴侣.");
	
	for(p = user->begin(); p!=user->end(); p++)
	{
		couple_ob = p->second;
		if(couple_ob->querystr("id") == target)
			break;
		couple_ob = NULL;
	}
	
	if( !couple_ob )
		return notify_fail("你的伴侣现在听不见你，或者已经离开游戏了。");

	if (couple_ob->querystr("gender") != "女性")
	{
		strcpy(tmpstr1, "老婆");
		strcpy(tmpstr2, "老公");
	} 
	else
	{
		strcpy(tmpstr1, "老公");
		strcpy(tmpstr2, "老婆");
	}
	
	tell_object(me, snprintf(msg, 255, "你对%s%s说：%s", tmpstr2, couple_ob->name(1), arg));
	tell_object(couple_ob, snprintf(msg, 255, "%s%s对你说：%s", tmpstr1, me->name(1), arg));
	
	return 1;
}

string query_autoload()
{
	list = all_inventory(this_player());
	i = sizeof(list);
	while (i--)
	{
		if (( list[i]->query("id")) == "marrycard")
			cardname = list[i]->query("name");
	}
	
	sscanf(cardname,"你和%s的婚约" ,target);
	return target;
}

void autoload(string arg)
{
	int i;
	object couple_ob;
	object me;
	char tmpstr1[5], tmpstr2[5], str1[3], str2[3];
	
	couple_ob = find_player(arg);
	if (couple_ob)
	{
		if ( couple_ob->querystr("gender") != "女性")
		{
			strcpy(tmpstr1, "老公");
			strcpy(tmpstr2, "老婆");
		} else
		{
			strcpy(tmpstr1, "老婆");
			strcpy(tmpstr2, "老公");
		}
		write(sprintf( "你的%s也在这里，快去找啦...",tmpstr1));
		tell_object(couple_ob ,
			sprintf(  "你的%s来啦,快去接..." , tmpstr2));
		//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") );
	}
	set_name("你和"+arg+"的婚约");
}
*/

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp
/*********************************
// marry_card.c
#include <ansi.h>

inherit ITEM;
virtual void create()
{
        set_name("婚约", ({"marrycard"}) );
        set_weight(10);
        set("no_get",1);
        set("no_beg",1);
        set("no_put",1);
        set("no_steal",1);
        set("no_drop","你的婚约不能丢弃, 只能去红娘庄解除婚约。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("material", "paper");
        }
}

//void init()
//{
//        add_action("do_put","put");
//        add_action("do_coupletalk", "coupletalk");
//        add_action("do_coupletalk", "ct");
//        add_action("do_cemote", "cm" );
//}

int do_put(string arg)
{
        object me = this_player();
        if(arg!="marrycard in corpse") return 0;
        else
        {
          tell_object(me,"这是你最珍贵的东西，怎么可以放到那儿去？\n");
          return 1;
        }
}

int do_cemote(string arg)
{
        object *list, me;
        object couple_ob;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--)
        {
              if (( list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                return notify_fail("你没有伴侣.\n");

        couple_ob = find_player(target);
        if( !couple_ob )
          return notify_fail("你的伴侣现在听不见你，或者已经离开游戏了。\n");
        if ( couple_ob->querystr("gender") != "女性")
        {
                tmpstr1 = "老婆"; tmpstr2 = "老公";
                str1 = "她"; str2 = "他";
        } else
        {
                tmpstr1 = "老公"; tmpstr2 = "老婆";
                str1 = "他"; str2 = "她";
        }

        if (!arg)
        {
                write( MAG "你又深情的想念你的爱侣了。\n" NOR);
                tell_room(environment(me), CYN+ me->name()+
                "又深情的想念"+str1+"的爱侣"+  couple_ob->name()+
                "了。\n" +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                又在深情的想你了\n"NOR, tmpstr1,me->name(1) ));
                return 1;
        }
        if (environment(me) == environment(couple_ob ) )
        {
           if (arg == "kiss")
           {
              write( MAG "你拥住你的爱侣，深深的一吻，许久...许久...\n" NOR);
              tell_room(environment(me), CYN+ me->name()+
              "拥住"+ couple_ob->name()+"，深深的一吻。\n"
                +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                拥住你，深深的一吻，许久...许久...\n"NOR,tmpstr1,me->name(1)));
           }
           if (arg == "bye")
           {
              write( MAG "你含泪凝望着你的爱侣，哽咽道: 又要分手了，何时才能长相聚不分离呀......\n" NOR);
              tell_room(environment(me), CYN+ me->name()+
              "拥住"+ couple_ob->name()+"，深深的一吻。\n"
                +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                含泪凝望着你，哽咽道: 又要分手了，何时才能长相聚不分离呀......\n"NOR,tmpstr1,me->name(1)));
           }
        }

        return 1;
}

int do_coupletalk(string arg)
{
        object *list, me;
        object couple_ob;
        string target, tmpstr1, tmpstr2;
        string cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--)
        {
              if (( list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                return notify_fail("你没有伴侣.\n");

        couple_ob = find_player(target);
        if( !couple_ob )
           return notify_fail("你的伴侣现在听不见你，或者已经离开游戏了。\n");
        if ( couple_ob->querystr("gender") != "女性")
        {
                tmpstr1 = "老婆";
                tmpstr2 = "老公";
        } else
        {
                tmpstr1 = "老公";
                tmpstr2 = "老婆";
        }

        write(sprintf(MAG"你对%s %s 说：%s\n"NOR,
                tmpstr2,couple_ob->name(1), arg ));
        tell_object(couple_ob, sprintf(MAG "%s %s 对你说：%s\n"NOR,
               tmpstr1,me->name(1), arg ));

        return 1;
}

void owner_is_killed()
{
        object me = this_player();
        write(HIW"尸体中的婚卡化为云烟消失了……\n"NOR);
        destruct(this_object());
}

string query_autoload()
{
        object *list, me;
        object couple_ob;
        string target,cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--)
        {
              if (( list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        sscanf(cardname,"你和%s的婚约" ,target);
        return target;
}

void autoload(string arg)
{
        int i;
        object couple_ob;
        object me;
        string tmpstr, tmpstr1;

//        me = this_player();
        couple_ob = find_player(arg);
        if (couple_ob)
        {
             if ( couple_ob->querystr("gender") != "女性")
             {
                    tmpstr1 = "老公";
                    tmpstr = "老婆";
              } else
              {
                    tmpstr1 = "老婆";
                    tmpstr = "老公";
              }
              write(sprintf( MAG "你的%s也在这里，快去找啦...\n"NOR,tmpstr1));
              tell_object(couple_ob ,
              sprintf( MAG "你的%s来啦,快去接...\n" NOR, tmpstr));
//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") );
        }
        set_name("你和"+arg+"的婚约");
}

********/