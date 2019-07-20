/*
 * Scheduler.h
 *
 *  Created on: 14 jul. 2019
 *      Author: Rommel
 */

#ifndef INCLUDE_KERNEL_H_
#define INCLUDE_KERNEL_H_

#define SAVE_CONTEXT()           \
  asm volatile ( "push r4  \n\t" \
                 "push r5  \n\t" \
                 "push r6  \n\t" \
                 "push r7  \n\t" \
                 "push r8  \n\t" \
                 "push r9  \n\t" \
                 "push r10 \n\t" \
                 "push r11 \n\t" \
                 "push r12 \n\t" \
                 "push r13 \n\t" \
                 "push r14 \n\t" \
                 "push r15 \n\t" \
               );

#define RESTORE_CONTEXT()       \
  asm volatile ( "pop r15 \n\t" \
                 "pop r14 \n\t" \
                 "pop r13 \n\t" \
                 "pop r12 \n\t" \
                 "pop r11 \n\t" \
                 "pop r10 \n\t" \
                 "pop r9  \n\t" \
                 "pop r8  \n\t" \
                 "pop r7  \n\t" \
                 "pop r6  \n\t" \
                 "pop r5  \n\t" \
                 "pop r4  \n\t" \
                 "reti    \n\t" \
               );

/*
 * @startuml
    participant "app: Application" as app
    participant "cm: ContentManager" as cm
    participant "item: DownloadItem" as item

    activate app
    activate cm

    note over app: User enters media info page

    note over app: Check if item exists
    app->cm: findItem(itemId)
    cm->cm: lookup(itemId)

    alt item found
        cm-->app: item
    else not found
        cm-->app: null
        app->cm: createItem(itemId, contentURL)
        cm->item: new(itemId, contentURL)
        activate item
        cm-->app: item

        app->cm: loadMetadata()
        note over cm
            Download and parse manifest, save in db
        end note
        cm-->app: onTracksAvailable
        cm-->app: onDownloadMetadata
        note over app: * See //track-selection// flow
    end group
    note over app: app is ready to start downloading
    app->item: startDownload()

    @enduml
 * */
void KernelRun(void);
void KernelInitTimer(void);
void KernelCallBack();


#endif /* INCLUDE_KERNEL_H_ */
