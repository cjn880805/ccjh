//marry_card.h

//Sample for ITEM ��Ʒ��
//coded by Fisho
//data: 2000-11-25

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CImarry_card);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Լ");	//set item name
	
	set_weight(10);
	set("no_get",1);
	set("no_beg",1);
	set("no_put",1);
	set("no_steal",1);
	set("no_drop","��Ļ�Լ���ܶ���, ֻ��ȥ����ׯ�����Լ��");
	set("unit", "��");
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

	if (sscanf(cardname, "���%s�Ļ�Լ" , target) != 1)
		return notify_fail("��û�а���.");
	
	user = users();
	for( p = user->begin(); p!= user->end(); p++)
	{
		couple_ob = p->second;
		if(couple_ob->querystr("id") == target)
			break;
		couple_ob = NULL;
	}

	if( !couple_ob )
		return notify_fail("��İ��������������㣬�����Ѿ��뿪��Ϸ�ˡ�");

	char tmpstr1[5], tmpstr2[5], str1[3], str2[3];
	
	if (couple_ob->querystr("gender") != "Ů��")
	{
		strcpy(tmpstr1,"����"); 
		strcpy(tmpstr2, "�Ϲ�");
		strcpy(str1, "��"); 
		strcpy(str2, "��");
	} 
	else
	{
		strcpy(tmpstr1,"�Ϲ�"); 
		strcpy(tmpstr2, "����");
		strcpy(str1, "��"); 
		strcpy(str2, "��");
	}
	
	if (arg.length())
	{
		tell_object(me,  "���������������İ����ˡ�" );
		MessageVision(me, "chat", snprintf(msg, 255, "%s�����������%s�İ���%s�ˡ�", 
			me->name(), str1, couple_ob->name(), me, couple_ob);

		tell_object(couple_ob, snprintf(msg, 255, "%s%s���������������", tmpstr1,me->name(1)));
		return 1;
	}

	if (me->environment() == couple_ob->environment() )
	{
		if (arg == "kiss")
		{
			tell_object(me, "��ӵס��İ��£������һ�ǣ����...���..." );
			MessageVison(me, "chat", snprintf(msg, 255, "%sӵס%s�������һ�ǡ�", 
				me->name(), couple_ob->name()), me, couple_ob);

			tell_object(couple_ob, snprintf(msg, 255, "%s%sӵס�㣬�����һ�ǣ����...���...", tmpstr1, me->name(1)));
		}

		if (arg == "bye")
		{
			tell_object(me,  "�㺬����������İ��£����ʵ�: ��Ҫ�����ˣ���ʱ���ܳ���۲�����ѽ......" );
			MessageVision(me, "chat", snprintf(msg, 255, "%sӵס%s�������һ�ǡ�",
				me->name(), couple_ob->name(), me, couple_ob);

			tell_object(couple_ob, snprintf(msg, 255, "%s%s�����������㣬���ʵ�: ��Ҫ�����ˣ���ʱ���ܳ���۲�����ѽ......",tmpstr1,me->name(1)));
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
	
	if (sscanf(cardname, "���%s�Ļ�Լ" ,target) != 1)
		return notify_fail("��û�а���.");
	
	for(p = user->begin(); p!=user->end(); p++)
	{
		couple_ob = p->second;
		if(couple_ob->querystr("id") == target)
			break;
		couple_ob = NULL;
	}
	
	if( !couple_ob )
		return notify_fail("��İ��������������㣬�����Ѿ��뿪��Ϸ�ˡ�");

	if (couple_ob->querystr("gender") != "Ů��")
	{
		strcpy(tmpstr1, "����");
		strcpy(tmpstr2, "�Ϲ�");
	} 
	else
	{
		strcpy(tmpstr1, "�Ϲ�");
		strcpy(tmpstr2, "����");
	}
	
	tell_object(me, snprintf(msg, 255, "���%s%s˵��%s", tmpstr2, couple_ob->name(1), arg));
	tell_object(couple_ob, snprintf(msg, 255, "%s%s����˵��%s", tmpstr1, me->name(1), arg));
	
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
	
	sscanf(cardname,"���%s�Ļ�Լ" ,target);
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
		if ( couple_ob->querystr("gender") != "Ů��")
		{
			strcpy(tmpstr1, "�Ϲ�");
			strcpy(tmpstr2, "����");
		} else
		{
			strcpy(tmpstr1, "����");
			strcpy(tmpstr2, "�Ϲ�");
		}
		write(sprintf( "���%sҲ�������ȥ����...",tmpstr1));
		tell_object(couple_ob ,
			sprintf(  "���%s����,��ȥ��..." , tmpstr2));
		//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") );
	}
	set_name("���"+arg+"�Ļ�Լ");
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
        set_name("��Լ", ({"marrycard"}) );
        set_weight(10);
        set("no_get",1);
        set("no_beg",1);
        set("no_put",1);
        set("no_steal",1);
        set("no_drop","��Ļ�Լ���ܶ���, ֻ��ȥ����ׯ�����Լ��\n");
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
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
          tell_object(me,"�����������Ķ�������ô���Էŵ��Ƕ�ȥ��\n");
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

        if (sscanf(cardname,"���%s�Ļ�Լ" ,target)!=1)
                return notify_fail("��û�а���.\n");

        couple_ob = find_player(target);
        if( !couple_ob )
          return notify_fail("��İ��������������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
        if ( couple_ob->querystr("gender") != "Ů��")
        {
                tmpstr1 = "����"; tmpstr2 = "�Ϲ�";
                str1 = "��"; str2 = "��";
        } else
        {
                tmpstr1 = "�Ϲ�"; tmpstr2 = "����";
                str1 = "��"; str2 = "��";
        }

        if (!arg)
        {
                write( MAG "���������������İ����ˡ�\n" NOR);
                tell_room(environment(me), CYN+ me->name()+
                "�����������"+str1+"�İ���"+  couple_ob->name()+
                "�ˡ�\n" +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                ���������������\n"NOR, tmpstr1,me->name(1) ));
                return 1;
        }
        if (environment(me) == environment(couple_ob ) )
        {
           if (arg == "kiss")
           {
              write( MAG "��ӵס��İ��£������һ�ǣ����...���...\n" NOR);
              tell_room(environment(me), CYN+ me->name()+
              "ӵס"+ couple_ob->name()+"�������һ�ǡ�\n"
                +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                ӵס�㣬�����һ�ǣ����...���...\n"NOR,tmpstr1,me->name(1)));
           }
           if (arg == "bye")
           {
              write( MAG "�㺬����������İ��£����ʵ�: ��Ҫ�����ˣ���ʱ���ܳ���۲�����ѽ......\n" NOR);
              tell_room(environment(me), CYN+ me->name()+
              "ӵס"+ couple_ob->name()+"�������һ�ǡ�\n"
                +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s
                �����������㣬���ʵ�: ��Ҫ�����ˣ���ʱ���ܳ���۲�����ѽ......\n"NOR,tmpstr1,me->name(1)));
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

        if (sscanf(cardname,"���%s�Ļ�Լ" ,target)!=1)
                return notify_fail("��û�а���.\n");

        couple_ob = find_player(target);
        if( !couple_ob )
           return notify_fail("��İ��������������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
        if ( couple_ob->querystr("gender") != "Ů��")
        {
                tmpstr1 = "����";
                tmpstr2 = "�Ϲ�";
        } else
        {
                tmpstr1 = "�Ϲ�";
                tmpstr2 = "����";
        }

        write(sprintf(MAG"���%s %s ˵��%s\n"NOR,
                tmpstr2,couple_ob->name(1), arg ));
        tell_object(couple_ob, sprintf(MAG "%s %s ����˵��%s\n"NOR,
               tmpstr1,me->name(1), arg ));

        return 1;
}

void owner_is_killed()
{
        object me = this_player();
        write(HIW"ʬ���еĻ鿨��Ϊ������ʧ�ˡ���\n"NOR);
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

        sscanf(cardname,"���%s�Ļ�Լ" ,target);
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
             if ( couple_ob->querystr("gender") != "Ů��")
             {
                    tmpstr1 = "�Ϲ�";
                    tmpstr = "����";
              } else
              {
                    tmpstr1 = "����";
                    tmpstr = "�Ϲ�";
              }
              write(sprintf( MAG "���%sҲ�������ȥ����...\n"NOR,tmpstr1));
              tell_object(couple_ob ,
              sprintf( MAG "���%s����,��ȥ��...\n" NOR, tmpstr));
//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") );
        }
        set_name("���"+arg+"�Ļ�Լ");
}

********/